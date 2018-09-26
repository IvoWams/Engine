#include <interface/InterfaceObject.h>
#include <global/Globals.h>

InterfaceObject::InterfaceObject(double _x, double _y, double _w, double _h){
	children = new vector<InterfaceObject*>;

	x = _x;
	y = _y;
	width = _w;
	height = _h;
	focus	 = false;	// if mouse over
	pressed	 = false;	// if pressed by mouse
}

InterfaceObject::InterfaceObject(InterfaceObject* original){
	children = new vector<InterfaceObject*>;

	x		= original->getX();
	y		= original->getY();
	width	= original->getWidth();
	height	= original->getHeight();
	focus	= original->isFocussed();
	pressed	= original->isPressed();
}

InterfaceObject::~InterfaceObject(){
	delete children;
}

void    InterfaceObject::enable(){
	Globals::getGlobals()->engine->getInterfaceHandler()->addObject(this);
	
	// An object needs to clarify what subobjects it want to add to the interfacehandler
}

void    InterfaceObject::disable(){
	// remove itself from the handler
	Globals::getGlobals()->engine->getInterfaceHandler()->delObject(this);
	// and all its children
	for(int i=0;i<children->size();++i)
	    Globals::getGlobals()->engine->getInterfaceHandler()->delObject((*children)[i]);
}

void	InterfaceObject::setPosition(double _x, double _y){
	// This sets this current objects position only
	x = _x;
	y = _y;
}

void	InterfaceObject::resize(double _w, double _h){
	width = _w;
	height = _h;
}

void	InterfaceObject::replace(double _x, double _y){
	x+=_x;
	y+=_y;
	for(int i=0;i<children->size();++i)
		(*children)[i]->replace(_x, _y);
}

// Basic implementation, overwrite if needed
bool		InterfaceObject::hit(double px, double py){
	// returns true of px:py hits the object, object is considered a rectangle
	return(px >= x && px <= x+width && py >= y && py <= y+height);
}

void	InterfaceObject::addObject(InterfaceObject* io){
	// By default, child objects do not have a relative position to the parent position
	children->push_back(io);
}

void	InterfaceObject::delObject(InterfaceObject* io){
	for(int i=0;i<children->size();++i)
		if((*children)[i]==io)
			children->erase(children->begin()+i);
}

bool	InterfaceObject::hasObject(InterfaceObject* io){
	for(int i=0;i<children->size();++i)
		if((*children)[i]==io)
			return true;
	return false;
}

void	InterfaceObject::paint(){}
