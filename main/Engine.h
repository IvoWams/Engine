using namespace std;

#include <iostream>
#include <stdlib.h>
#include <global/Globals.h>
#include <global/GlobalValues.h>
#include <main/MainEngine.h>
#include <windows.h>
#include <gl/gl.h>

#ifndef ENGINE_H
#define ENGINE_H

int 				EngineInitGL();
void 				EngineKillGLWindow();
bool				EngineCreateGLWindow(char*, int, int, int, int, int, bool);
void				EngineReSizeGLScene(int, int);
LRESULT CALLBACK 	EngineWndProc(HWND, UINT, WPARAM, LPARAM);
int WINAPI 			EngineWinMain(HINSTANCE, HINSTANCE, LPSTR, int);

#endif
