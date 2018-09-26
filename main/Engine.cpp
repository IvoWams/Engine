#include <main/Engine.h>
#include <fstream>

LRESULT CALLBACK EngineWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	// This method reads the basic windows interfacing and passes it to the engine
	// For mousehandling and inputhandling
	Globals*	globals	= Globals::getGlobals();
	MainEngine* engine	= globals->engine;
	
    switch (message){
    	case WM_CREATE:
        	return 0;

    	case WM_CLOSE:{
        	PostQuitMessage (0);
        	return 0;
        }

    	case WM_DESTROY:
        	return 0;

        case WM_KEYDOWN:{
        	engine->getInputHandler()->keyDown(wParam);
         	return 0;
        }

        case WM_KEYUP:{
        	engine->getInputHandler()->keyUp(wParam);
        	return 0;
        }

        case WM_MOUSEMOVE:{
/*
			int middlex =(engine->getRenderer()->getWidth()/2);
			int middley = (engine->getRenderer()->getHeight()/2);

        	POINT mousepos;
        	GetCursorPos(&mousepos);

			if(mousepos.x == middlex && mousepos.y == middley)
				return 0;

			engine->getMouseHandler()->mouseMove( mousepos.x - middlex, mousepos.y - middley );

			SetCursorPos(middlex, middley);
*/
        	return 0;

        }

        case WM_LBUTTONDOWN:{
            engine->getMouseHandler()->mouseDown(0);
        	return 0;
        }

        case WM_LBUTTONUP:{
            engine->getMouseHandler()->mouseUp(0);
        	return 0;
        }

        case WM_MBUTTONDOWN:{
            engine->getMouseHandler()->mouseDown(1);
        	return 0;
        }

        case WM_MBUTTONUP:{
            engine->getMouseHandler()->mouseUp(1);
        	return 0;
        }

        case WM_RBUTTONDOWN:{
            engine->getMouseHandler()->mouseDown(2);
        	return 0;
        }

        case WM_RBUTTONUP:{
            engine->getMouseHandler()->mouseUp(2);
        	return 0;
        }

        default:
                return DefWindowProc (hWnd, message, wParam, lParam);
    }
}

void EngineReSizeGLScene(int width, int height){
	if (height==0)height=1;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,1.0,500.0);				// our view boundaries
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int EngineInitGL(){

	glShadeModel(GL_SMOOTH);
//    glClearColor (0.1f, 0.3f, 0.5f, 1.0f);
//    glClearColor (0.0f, 0.0f, 0.0f, 1.0f);

//    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0f);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glDepthFunc(GL_LEQUAL);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	
	return TRUE;
}

void EngineKillGLWindow(){
	Globals*	globals	= Globals::getGlobals();
	MainEngine* engine	= globals->engine;
	bool		fullscreen=false;
	
	// Error messages disabled, enginekillglwindow TRIES to kill a window, if its not there; who cares

	if(fullscreen){
		ChangeDisplaySettings(NULL,0);
		ShowCursor(TRUE);
	}

	if(globals->hRC){
		if(!wglMakeCurrent(NULL,NULL))
//			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		if(!wglDeleteContext(globals->hRC))
//			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		globals->hRC=NULL;
	}

	if(globals->hDC && !ReleaseDC(globals->hWnd,globals->hDC)){
//		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		globals->hDC=NULL;
	}

	if(globals->hWnd && !DestroyWindow(globals->hWnd)){
//		MessageBox(NULL,"Could Not Release globals->hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		globals->hWnd=NULL;
	}

	if (!UnregisterClass("OpenGL",globals->hInstance)){
//		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		globals->hInstance=NULL;
	}
}

bool EngineCreateGLWindow(char* title, int left, int top, int width, int height, int bits, bool fullscreenflag){
	Globals*	globals	= Globals::getGlobals();
	MainEngine* engine	= globals->engine;

	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values

	WindowRect.left=(long)left;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)top;			// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	bool fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	globals->hInstance	= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) EngineWndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= globals->hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if(!RegisterClass(&wc)){
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}

	if(fullscreen){
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if(ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL){
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if(MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","Unsupported format",MB_YESNO|MB_ICONEXCLAMATION)==IDYES){
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}else{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if(fullscreen){												// Are We Still In Fullscreen Mode?
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
//		ShowCursor(FALSE);										// Hide Mouse Pointer
	}else{
//		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
//		Use WS_POPUP to remove all window frame graphics
//		dwStyle = WS_POPUP;
	}

//	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if(!(globals->hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								WindowRect.left, WindowRect.top,	// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								globals->hInstance,							// Instance
								NULL))){							// Dont Pass Anything To WM_CREATE

		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}
	
	// Multi Monitor Support
	// Enum Monitor
//	MONITORINFOEX	monitorinfo;
//	monitorinfo.cbSize = sizeof(MONITORINFOEX);
//	GetMonitorInfo(MonitorFromWindow(globals->hWnd, MONITOR_DEFAULTTONEAREST));

//	ofstream fout("monitorinfo.txt", ios::out);
	
//	fout.close();
	
	
	static	PIXELFORMATDESCRIPTOR pfd=	{			// pfd Tells Windows How We Want Things To Be
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if(!(globals->hDC=GetDC(globals->hWnd))){							// Did We Get A Device Context?
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(globals->hDC,&pfd))){// Did Windows Find A Matching Pixel Format?
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(globals->hDC,PixelFormat,&pfd)){		// Are We Able To Set The Pixel Format?
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(globals->hRC=wglCreateContext(globals->hDC))){				// Are We Able To Get A Rendering Context?
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(globals->hDC,globals->hRC)){					// Try To Activate The Rendering Context
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(globals->hWnd,SW_SHOW);					// Show The Window

//	Enable next line to have the window always in front of everything
//	SetWindowPos(globals->hWnd, HWND_TOPMOST, left, top, width, height, SWP_SHOWWINDOW);

//	SetForegroundWindow(globals->hWnd);					// Slightly Higher Priority
	SetFocus(globals->hWnd);							// Sets Keyboard Focus To The Window
	EngineReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if(!EngineInitGL()){									// Initialize Our Newly Created GL Window
		EngineKillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

int WINAPI EngineWinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow){
	// Retrieve default renderer from globals
	Globals*	globals	= Globals::getGlobals();
	MainEngine* engine	= globals->engine;

//	bool		fullscreen=true;

	Renderer*	renderer = engine->getRenderer();

/*
	if(!renderer->getResolution()->isAvailable()){
		// Save mode:
		MessageBox(NULL, "The currently selected resolution is unavailable.\n\nRunning in a safe resolution instead.", "PROBLEM", MB_OK);
		renderer->changeResolution(5, fullscreen);
	}
*/

/*
	// Create Our OpenGL Window
	if(!EngineCreateGLWindow("Engine",
					   renderer->getResolution()->getWidth(),
					   renderer->getResolution()->getHeight(),
					   renderer->getResolution()->getBPP(),
					   fullscreen))
		return 0;
*/

//	ShowCursor(false);

	// Boot up engine
	engine->doLoop();

	// Engine quits, destroy app
    DestroyWindow (globals->hWnd);

	MSG msg;
    return msg.wParam;
}
