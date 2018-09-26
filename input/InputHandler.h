// A class for handling keyboard activity
// Use keyUp/Down for handling individual keystrokes
// Use keyBind to trigger custom values attached to individual keystrokes (so you can make a nice customize control thingy)

using namespace std;

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <input/InputListener.h>
#include <input/KeyBind.h>
#include <vector>

class InputHandler{
	private:
		vector<InputListener*>*	listeners;

		vector<KeyBind*>*       keybindings;
		vector<int>				keyhistory;
		bool					keymap[255];

	public:
		InputHandler();
		~InputHandler();

		void				addListener(InputListener*);
		void				delListener(InputListener*);
		
		void                addBind(int, int);
		void				delBind(int);

		void				keyUp(int);
		void				keyDown(int);

};

#endif
