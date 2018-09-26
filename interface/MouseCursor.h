// Custom mouse pointer :)

using namespace std;

#ifndef MOUSECURSOR_H
#define MOUSECURSOR_H

#include <interface/InterfaceObject.h>
#include <input/MouseListener.h>
#include <global/GlobalValues.h>
#include <global/Color.h>

class MouseCursor : public InterfaceObject,
					public MouseListener {
	private:
		bool	mousedown;

		void	vlak(double, double);

	public:
		MouseCursor(double, double);
		~MouseCursor();

		double	getX(){ return x; }
		double	getY(){ return y; }

		void	setPosition(double, double);

		void	onMouseMove(double, double);
		void	onMouseDown(double);
		void	onMouseUp(double);
		

		void	paint();
};

#endif


