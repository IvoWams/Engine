// Basic interface functionality
// This source provides the methods template for a gui

using namespace std;

#ifndef INTERFACEOBJECT_H
#define INTERFACEOBJECT_H

#include <vector>

class InterfaceObject {
	private:

	protected:
		vector<InterfaceObject*>*	children;

		double	x;
		double	y;
		double	width;
		double	height;

		bool	focus;
		bool	pressed;
		bool    mouseover;

	public:
		InterfaceObject(double, double, double, double);
		InterfaceObject(InterfaceObject*);
		virtual	~InterfaceObject();

		// outside reading/setting
		void    setX(double _x){ x = _x; }
		double	getX()			{ return x; }
		void    setY(double _y){ y = _y; }
		double	getY()			{ return y; }
		void    setWidth(double _width){ width = _width; }
		double	getWidth()		{ return width; }
		void    setHeight(double _height){ height = _height; }
		double	getHeight()		{ return height; }
		
		bool	isFocussed()	{ return focus; }
		bool	isBlurred()		{ return !focus; }
		bool	isPressed()		{ return pressed; }
		bool	isReleased()	{ return !pressed; }
		bool    hasMouseOver()  { return mouseover; }
		bool    hasMouseOut()   { return !mouseover; }

		// outside modifiers
		virtual void    enable();       // where objects can determine what subobjects are added to the handlers
		virtual void    disable();      		// removes itself and its children from the handlers

		void	setPosition(double, double);
		void	resize(double, double);
		void	replace(double, double);			// relative move including childs, usable with mousemoves

		void	setFocus()		{ focus = true; }
		void	setBlur()		{ focus = false; }
		void	setPress()		{ pressed = true; }
		void	setRelease()	{ pressed = false; }
		void    setMouseOver()  { mouseover = true; }
		void    setMouseOut()   { mouseover = false; }

		// return children
		vector<InterfaceObject*>*	getChildren()	{ return children; }
		void	addObject(InterfaceObject*);
		void	delObject(InterfaceObject*);
		bool	hasObject(InterfaceObject*);

		// recognition (ie is it hit @ Vector?)
		bool	hit(double, double);
		virtual void	paint();
};

#endif
