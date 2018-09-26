// Generic Trigger Listening Template

using namespace std;

#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <global/Vector.h>

class MouseListener {
	private:
	public:        
		MouseListener();
		virtual	~MouseListener();

		// Event methods to implement
		virtual void	onMouseMove(double, double);
		virtual void	onMouseDown(int);
		virtual void	onMouseUp(int);
};

#endif
