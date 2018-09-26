// Input field

using namespace std;

#ifndef INPUTBOX_H
#define INPUTBOX_H

#include <timer/Timer.h>
#include <timer/TimerListener.h>
#include <interface/InterfaceObject.h>
#include <interface/InterfaceListener.h>
#include <input/InputListener.h>
#include <interface/Label.h>
#include <stdio.h>
#include <global/GlobalValues.h>
#include <global/Vector.h>

class InputBox : public InterfaceObject,
				 public InputListener,
				 public TimerListener {

	private:
//		Label*	label;

		Font*   font;
		char*   text;
		
		Color*  color;
		
		int		maxlength;

		void	onKeyDown(int);
		void	onKeyUp(int);
		bool	caps;
		int		cursor;

		void	addChar(char);

		bool    paintcursor;
		Timer*  blinker;

	public:
		InputBox(int, int, int, int, Font*, int);
		~InputBox();

		bool	hit(Vector*);
		void	paint();

		char*	getValue();
		
		void    onTime(Timer*);
		
		void    onPress();
		void    onRelease();
};

#endif
