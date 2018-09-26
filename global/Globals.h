// Global Variables in a singleton

using namespace std;

#ifndef GLOBALS_H
#define GLOBALS_H

#include <main/MainEngine.h>
#include <windows.h>

class MainEngine;

class Globals {
	private:
		static Globals* globals;
		Globals();

	public:
		static Globals* getGlobals();		// Get constructed Globals here
		virtual ~Globals();

		// Ugly windows stuff
		HGLRC		hRC;
		HDC			hDC;
		HWND		hWnd;
		HINSTANCE	hInstance;
		MainEngine*	engine;
};

#endif
