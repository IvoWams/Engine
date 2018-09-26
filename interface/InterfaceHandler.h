// InterfaceHandler
// Manages interface objects, and creates triggers from user actions ...

using namespace std;

#ifndef INTERFACEHANDLER_H
#define INTERFACEHANDLER_H

#include <interface/InterfaceObject.h>
#include <interface/InterfaceListener.h>
#include <interface/MouseCursor.h>
#include <input/MouseListener.h>
#include <vector>

class InterfaceHandler : public MouseListener {

	private:
		vector<InterfaceListener*>*	listeners;
		vector<InterfaceObject*>*	objects;
		
		InterfaceObject*            current_focus;      // keeps track
		InterfaceObject*            current_mouseover;  // needs to be null at start

	public:
		InterfaceHandler();
		~InterfaceHandler();

		void	addListener(InterfaceListener*);
		void	delListener(InterfaceListener*);
		bool	hasListener(InterfaceListener*);
		
		void    addObject(InterfaceObject*);
		void    delObject(InterfaceObject*);
		bool    hasObject(InterfaceObject*);

		void	replace(float, float);	// relative move and all childs

		// interface for the main engine
		void    focus(InterfaceObject*);        // Activate this object
		void	blur(InterfaceObject*);         // Something else has been clicked
		void    press(InterfaceObject*);        // Mousedown on this object
		void    release(InterfaceObject*);      // Mouseup on this object
		void    mouseover(InterfaceObject*);    // Mouse hovering over object
		void    mouseout(InterfaceObject*);     // mousecursor leaves
		void    change(InterfaceObject*);       // notifies listeners of a change in an object

		void    paint();
		
		// Reordering objects
		void    onTop(InterfaceObject*);        // Move interfaceobject on top
		
		// Mouse Listening (interaction)
		void	onMouseMove(double, double);
		void	onMouseDown(int);
		void	onMouseUp(int);

};

#endif

