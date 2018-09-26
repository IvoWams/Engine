using namespace std;

#ifndef MAINENGINE_H
#define MAINENGINE_H

#include <main/Engine.h>
#include <global/GlobalValues.h>
#include <timer/TimerHandler.h>
#include <texture/TextureHandler.h>
#include <global/Camera.h>
#include <collision/CollisionHandler.h>
#include <keyframe/KeyFrameHandler.h>
#include <interface/InterfaceHandler.h>
#include <input/InputHandler.h>
#include <input/MouseHandler.h>
#include <renderer/Renderer.h>
#include <font/FontHandler.h>
#include <main/MainListener.h>
// #include <ddraw>

#include <gl/gl.h>
#include <gl/glu.h>
#include <vector>
#include <time.h>

#include <fstream>

// BOOL WINAPI enumerater(GUID FAR*, LPSTR, LPSTR, LPVOID, HMONITOR);

class MainEngine {

	private:
		Renderer*				renderer;
		vector<RootObject*>*	objects;

		CollisionHandler*		collisionhandler;
		KeyFrameHandler*		keyframehandler;
		InterfaceHandler*		interfacehandler;
		InputHandler*			inputhandler;
		MouseHandler*			mousehandler;

		TimerHandler*			timerhandler;

		TextureHandler*			texturehandler;
		FontHandler*			fonthandler;

		// LPDIRECTDRAW7			lpDD;

		// General engine variables
		bool			isRunning;

		long			timepos;		// time stamp
		long			prev_timepos;	// prev timestamp

		double			frametime;		// duration of last frame
		int				sleep_value;
		int				fps;			// frames per second
		int				frames;
		double			duration;		// total duration of the engine, verrrry long, in msec
		bool			waitForVsync;

		Camera*			defaultcam;


		// Listeners to this main engine
		vector<MainListener*>*	listeners;

	public:
		MainEngine();
		~MainEngine();

		// Handle listeners to main engine
		void	addListener(MainListener*);
		void	delListener(MainListener*);

		void    addObject(RootObject*);
		void	delObject(RootObject*);
		bool	hasObject(RootObject*);

		void	onTop(RootObject*);		// move this object to the end of the drawing order
		void	onBottom(RootObject*);	// move this object to the start of the drawing order

		// delete?:
  		vector<RootObject*>*	getObjects(){ return objects; }

		// Demo can manipulate handlers if need be
		TimerHandler*		getTimerHandler(){ return timerhandler; }
        TextureHandler*     getTextureHandler(){ return texturehandler; }
        InterfaceHandler*   getInterfaceHandler(){ return interfacehandler; }
        InputHandler*       getInputHandler(){ return inputhandler; }
        MouseHandler*       getMouseHandler(){ return mousehandler; }
		KeyFrameHandler*	getKeyFrameHandler(){ return keyframehandler; }
		CollisionHandler*   getCollisionHandler(){ return collisionhandler; }
		FontHandler*		getFontHandler(){ return fonthandler; }
		Renderer*			getRenderer(){ return renderer; }
//		CacheSynchronizer*	getCacheSynchronizer(){ return cachesynchronizer; }

		void				nextFrame();


		int					getFPS(){ return (int)(1000*frames/duration); }

		double				getFrameTime(){ return frametime; }
		int					getFrames(){ return frames; }
		double				getDuration(){ return duration; }

		// Set application CPU and Priority
		void				setSleep(int _sleep_value){ sleep_value = _sleep_value; }
		void				setPriorityClass(int);
		void				setThreadPriority(int);

		// Main engine loop
		void	doLoop();

		// Quit
		void	quit();

};

#endif


