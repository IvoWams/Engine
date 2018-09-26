#include <renderer/Renderer.h>
#include <global/Globals.h>
#include <main/Engine.h>

Renderer::Renderer(){
	left = 0;
	top = 0;
	width = 640;
	height = 480;
	bpp = 16;
	fullscreen = false;

//	resolutions = new vector<ScreenResolution*>;

	// Fill resolutions
//	resolutions->push_back(new ScreenResolution(true, 400, 300, 16)); //0
//	resolutions->push_back(new ScreenResolution(true, 400, 300, 32)); //1

//	resolutions->push_back(new ScreenResolution(true, 640, 480, 16)); //2
//	resolutions->push_back(new ScreenResolution(true, 640, 480, 32)); //3
//	resolutions->push_back(new ScreenResolution(true, 800, 600, 16)); //4 
//	resolutions->push_back(new ScreenResolution(true, 800, 600, 32)); //5
//	resolutions->push_back(new ScreenResolution(true,1024, 768, 16)); //6
//	resolutions->push_back(new ScreenResolution(true,1024, 768, 32)); //7
//	resolutions->push_back(new ScreenResolution(true,1280, 960, 16)); //8
//	resolutions->push_back(new ScreenResolution(true,1280, 960, 32)); //9
//	resolutions->push_back(new ScreenResolution(true,1280, 1024, 16)); //10
//	resolutions->push_back(new ScreenResolution(true,1280, 1024, 32)); //11
//	resolutions->push_back(new ScreenResolution(true,1600,1200, 16)); //12
//	resolutions->push_back(new ScreenResolution(true,1600,1200, 32)); //13

//	resolution = (*resolutions)[7];
}

Renderer::~Renderer(){
//	for(int i=0;i<resolutions->size();++i)
//	    delete((*resolutions)[i]);
//	delete(resolutions);
}

void	Renderer::changeResolution(int _left, int _top, int _width, int _height, int _bpp, bool _fullscreen){
//	EngineReSizeGLScene(resolution->getWidth(), resolution->getHeight());

	// Reset values
	left = _left;
	top = _top;
	width = _width;
	height = _height;
	bpp = _bpp;
	fullscreen = _fullscreen;

	// Try to kill the current window (if its there)
	EngineKillGLWindow();
	
	// Go and create a window!
	EngineCreateGLWindow("Engine",
							left,
							top,
							width,
							height,
							bpp,
							fullscreen);
}

void	Renderer::setOrthoMode(int l, int t, int w, int h){
	glDisable(GL_LIGHTING);         // No lighting on 2D objects
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho( l, l+w, t+h, t, 0, 1 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void    Renderer::setOrthoMode(){
	setOrthoMode(0,0,width, height);
}

void	Renderer::setPerspectiveMode(){
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void	Renderer::setClipping(int x, int y, int w, int h){
	// The following code sets up a clipping rectangle:

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	// Determine that the entire projection plane is the size of the inputbox
	glOrtho( x, x+w, y+h, y, 0, 1 );

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Then determine that the entire inputbox is viewed on its original location
	glViewport(x, height - y - h, w, h);
//	glViewport(x, y - height, width, height);

	// Make sure u use setNoClipping before setting up another clipping window
}

void	Renderer::setNoClipping(){
	// Returning to the previous projection matrix
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// Returning viewport to its original size
	glViewport(0, 0, width, height);

}


void	Renderer::start(){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//	glLoadIdentity();
}

void	Renderer::finish(){
//	glFlush();
}

