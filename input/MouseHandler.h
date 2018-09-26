// Mouse Handler

using namespace std;

#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <interface/MouseCursor.h>
#include <input/MouseListener.h>
#include <global/Vector.h>
#include <vector>

class MouseHandler {
	private:
		
		vector<MouseListener*>*	listeners;
		MouseCursor*    		mousecursor;
		bool    				hidden;
		
		double                  boundary_left;
		double                  boundary_right;
		double                  boundary_top;
		double                  boundary_bottom;

	public:
		MouseHandler();
		~MouseHandler();

		void	addListener(MouseListener*);
		void	delListener(MouseListener*);
		bool	hasListener(MouseListener*);
		
		MouseCursor*    getMouseCursor(){ return mousecursor; }

		// Neat options
		void    setMouse(double, double);                       // set mouse to x:y
		void    setBoundary(double, double, double, double);    // limit mousemovement between boundary
		void    resetBoundary();                                // set boundary to screen resolution
		void    showMouse(bool);
		
		void	mouseMove(double, double);
		void	mouseDown(int);
		void	mouseUp(int);
		
		void    paint();
};

#endif
