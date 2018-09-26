// Generic Input Listening template

using namespace std;

#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

class InputListener {
	private:
	public:        
		InputListener();
		virtual	~InputListener();
		
		virtual void    onKeybind(int);
		virtual void	onKeyDown(int);
		virtual void	onKeyUp(int);
};

#endif
