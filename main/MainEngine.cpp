#include <main/MainEngine.h>
#include <stdio.h>
#include <mmsystem.h>
#include <gl/glu.h>
#include <fstream>

MainEngine::MainEngine(){
	renderer			= new Renderer();	// GLRenderer()

	// Object container
	objects 			= new vector<RootObject*>;

	// KeyFrame Handler:
	keyframehandler 	= new KeyFrameHandler();

	// TimerHandler:
	timerhandler 		= new TimerHandler();

	// Mouse Handling:
	mousehandler        = new MouseHandler();

	// Interface Handling:
	interfacehandler    = new InterfaceHandler();

	// Make interfacehandler listen to mousehandler
	mousehandler->addListener(interfacehandler);

	// Input handling
	inputhandler        = new InputHandler();

	// Collision Handling:
	collisionhandler    = new CollisionHandler();

	// Texturehandler
    texturehandler      = new TextureHandler();

	// Font Handler:
	fonthandler 		= new FontHandler();

	// Main Loop Listener:
	listeners 			= new vector<MainListener*>;

	// Default camera (or nul camera)
	defaultcam          = new Camera();

	// Directx7 for reading scanlines
	// HRESULT ddrval = DirectDrawCreateEx( NULL, ( LPVOID* )&lpDD, IID_IDirectDraw7, NULL);

	// Basic engine values:
	isRunning		= true;

	timepos			= 0;
	prev_timepos	= 0;

	sleep_value = 0;
	fps			= 0;
	frames		= 0;
	frametime	= 0;
	duration    = 0;

}

MainEngine::~MainEngine(){

	delete listeners;
	delete fonthandler;
	delete texturehandler;
	delete timerhandler;
	delete objects;
	delete renderer;
}

void			MainEngine::addListener(MainListener* _mainlistener){
	listeners->push_back(_mainlistener);
}

void			MainEngine::delListener(MainListener* _mainlistener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_mainlistener)
			listeners->erase(listeners->begin()+i);
}

void    MainEngine::addObject(RootObject* rootobject){
//	objects->push_back(rootobject);

	// No objects? Push as first
	if(objects->size()==0){
		objects->push_back(rootobject);
		return;
	}

	// If order same as last object or greater, push it there (performance)
	if(objects->back()->order <= rootobject->order){
		objects->push_back(rootobject);
		return;
	}

	// In any other case:
	int i=0;
	while((*objects)[i]->order <= rootobject->order && i < objects->size())i++;
	objects->insert(objects->begin()+i, rootobject);

}

void	MainEngine::delObject(RootObject* rootobject){
    for(int i=0;i<objects->size();++i)
    	if((*objects)[i]==rootobject)
    	    objects->erase(objects->begin()+i);
}

bool	MainEngine::hasObject(RootObject* rootobject){
    for(int i=0;i<objects->size();++i)
    	if((*objects)[i]==rootobject)
            return true;
    return false;
}

void	MainEngine::onTop(RootObject* rootobject){
	// check first if it is available, otherwise it just adds it
	delObject(rootobject);
	addObject(rootobject);
}

void	MainEngine::onBottom(RootObject* rootobject){
	delObject(rootobject);
	objects->insert(objects->begin(), rootobject);
}

/*
BOOL WINAPI	enumerater(	GUID FAR* lpGUID,
								LPSTR lpDriverDescription,
								LPSTR lpDriverName,
								LPVOID lpContext,
								HMONITOR hm ){
	ofstream fout("monitor.txt", ios::out | ios::app);
	fout << "Found device " << lpGUID << ", " << lpDriverDescription << ", " << lpDriverName << ", " << hm << "\n";
	fout.close();
}
*/

void	MainEngine::nextFrame(){
	frames++;
	renderer->start();

	// first paint root objects container components
	renderer->setPerspectiveMode();

	// set camera
	gluLookAt(	defaultcam->getPosition()->x, defaultcam->getPosition()->y, defaultcam->getPosition()->z,
			  	defaultcam->getTarget()->x,defaultcam->getTarget()->y, defaultcam->getTarget()->z,
				0,0,1);

	// Paint nonflat objects stored in container
       for(int i=0;i<objects->size();++i)if(!(*objects)[i]->flat)(*objects)[i]->paint();

	// Set 2D orthogonal mode for interface painting
	renderer->setOrthoMode();

	// Paint flat objects stored in container
	for(int i=0;i<objects->size();++i)if((*objects)[i]->flat)(*objects)[i]->paint();

	// Paint interface
	interfacehandler->paint();  // Paint interface objects

	// Paint mouse over interface
	mousehandler->paint();      // Paint mouse cursor

	// Finish up rendering frame
	renderer->finish();

	// Sleep(sleep_value);
	// if(waitForVsync)lpDD->WaitForVerticalBlank(DDWAITVB_BLOCKBEGIN, NULL);
	SwapBuffers(Globals::getGlobals()->hDC);
}

void MainEngine::doLoop(){
	// For windows messages
	MSG msg;

	// Notify listeners that the loop is starting
	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onStart();

//	timeBeginPeriod(1);

//	ofstream fout("engine.txt", ios::out);

	// Bordering system for frame limiting
	LARGE_INTEGER	li;
	double			f;

	LARGE_INTEGER	left_border;
	LARGE_INTEGER	right_border;

	QueryPerformanceFrequency(&li);
	f = li.LowPart;

	// DirectDraw Enumerating Devices (same needed for OpenGL)
//	DirectDrawEnumerateEx	                DDENUM_NONDISPLAYDEVICES | DDENUM_ATTACHEDSECONDARYDEVICES | DDENUM_DETACHEDSECONDARYDEVICES
//	DirectDrawEnumerateEx(enumerater, NULL, DDENUM_NONDISPLAYDEVICES | DDENUM_ATTACHEDSECONDARYDEVICES | DDENUM_DETACHEDSECONDARYDEVICES);


//	glEnable(GL_TEXTURE_2D);
//	glDisable(GL_COLOR_MATERIAL);

	while(isRunning){	// c'est la main lup

		QueryPerformanceCounter(&left_border);		// Get starting left border

		nextFrame();

		// Check collisions
		collisionhandler->checkCollisions();

		// run keyframehandler
        keyframehandler->tick(frametime);

        // run timerhandler
		timerhandler->tick(frametime);

		// Trigger frame on listeners
		for(int i=0;i<listeners->size();++i)
			(*listeners)[i]->onFrame();

		// fetch windows messages (like ALT+F4 etc...)
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)){
            if (msg.message==WM_QUIT){
                isRunning = false;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }


		QueryPerformanceCounter(&right_border);
		frametime = (right_border.LowPart - left_border.LowPart)/f;
		duration+=frametime;
	}

	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onStop();
}

void	MainEngine::quit(){
	isRunning = false;
}

void	MainEngine::setPriorityClass(int _p){
	if(_p==0)SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
	if(_p==1)SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
	if(_p==2)SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);
	if(_p==3)SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
	if(_p==4)SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	if(_p==5)SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
}

void	MainEngine::setThreadPriority(int _p){
	SetThreadPriority(GetCurrentThread(), _p); // THREAD_PRIORITY_ABOVE_NORMAL);
}
