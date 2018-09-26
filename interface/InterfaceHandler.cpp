#include <interface/InterfaceHandler.h>
#include <global/Globals.h>
#include <interface/Pane.h>

InterfaceHandler::InterfaceHandler(){
	objects = new vector<InterfaceObject*>;
	listeners = new vector<InterfaceListener*>;
	
	current_focus = NULL;
	current_mouseover = NULL;
	// If these values are NULL, there are is no current focus or mouseover
	// so always check them befor using them
}

InterfaceHandler::~InterfaceHandler(){
	delete(listeners);
	delete(objects);
}

void	InterfaceHandler::addListener(InterfaceListener* _interfacelistener){
	listeners->push_back(_interfacelistener);
}

void	InterfaceHandler::delListener(InterfaceListener* _interfacelistener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_interfacelistener)
			listeners->erase(listeners->begin()+i);
}

bool	InterfaceHandler::hasListener(InterfaceListener* io){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==io)
			return true;
	return false;
}

void    InterfaceHandler::addObject(InterfaceObject* io){
//	objects->insert(objects->begin(), io);
	objects->push_back(io);
}

void    InterfaceHandler::delObject(InterfaceObject* io){
	for(int i=0;i<objects->size();++i)
	    if((*objects)[i]==io)
	        objects->erase(objects->begin()+i);
}

bool    InterfaceHandler::hasObject(InterfaceObject* io){
	for(int i=0;i<objects->size();++i)
	    if((*objects)[i]==io)
			return true;
	return false;
}

void	InterfaceHandler::onTop(InterfaceObject* io){
	// just reenable object
	io->disable();
	io->enable();
}

void	InterfaceHandler::focus(InterfaceObject* iobj){
	if(iobj->isFocussed())return;           // dont even try

	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onFocus(iobj);     // Notify focus event

	iobj->setFocus();                       // Set object
	current_focus = iobj;                   // Keep track
}

void	InterfaceHandler::blur(InterfaceObject* iobj){
	if(iobj->isBlurred())return;        // dont!

	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onBlur(iobj);

	iobj->setBlur();

}

void	InterfaceHandler::press(InterfaceObject* iobj){
	if(iobj->isPressed())return;                    // Dont even try
	// Special:
	if(dynamic_cast<Pane*>(iobj))onTop(iobj);       // If pressed object is a pane, put it on top

	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onPress(iobj);             // Notify press event

	iobj->setPress();                               // update object
}

void	InterfaceHandler::release(InterfaceObject* iobj){
	if(iobj->isReleased())return;

	for(int i=0;i<listeners->size();++i)            // basic notify etc...
		(*listeners)[i]->onRelease(iobj);

	iobj->setRelease();
}

void    InterfaceHandler::mouseover(InterfaceObject* iobj){
	if(iobj->hasMouseOver())return;                 // Dont even try
	
	        
	current_mouseover = iobj;

	for(int i=0;i<listeners->size();++i)            // basic notify etc...
		(*listeners)[i]->onMouseOver(iobj);
		
	iobj->setMouseOver();
}

void    InterfaceHandler::mouseout(InterfaceObject* iobj){
	if(iobj->hasMouseOut())return;                  // dont
	
	for(int i=0;i<listeners->size();++i)
	    (*listeners)[i]->onMouseOut(iobj);          // notify etc
	    
	iobj->setMouseOut();
}

void    InterfaceHandler::change(InterfaceObject* iobj){
	for(int i=0;i<listeners->size();++i)
	    (*listeners)[i]->onChange(iobj);
}

void    InterfaceHandler::paint(){
	for(int i=0;i<objects->size();++i)
	    (*objects)[i]->paint();
}

void	InterfaceHandler::onMouseMove(double x, double y){
	// Now actually determine mouseovers and outs:
	// Check objects from front to back, first one to hit the mousecursor, gets the mouseover
	// mouseover method (see above), notifies the previous mouse overed object with a mouseout notify

	// The x:y is actually a bit useless here since we are interested in the current position of the mousecursor
	// Might rewrite onMouseMove
	
	MouseCursor* mousecursor = Globals::getGlobals()->engine->getMouseHandler()->getMouseCursor();

	for(int i=objects->size()-1;i>=0;--i)   // note: check front objects to back
		if((*objects)[i]->hit(mousecursor->getX()+x, mousecursor->getY()+y)){
			if(current_mouseover)mouseout(current_mouseover);
			mouseover((*objects)[i]);
			return;
		}

    if(current_mouseover)mouseout(current_mouseover);
}

void	InterfaceHandler::onMouseDown(int button){
	// The same as mouseover, except call the methods focus and press

	MouseCursor* mousecursor = Globals::getGlobals()->engine->getMouseHandler()->getMouseCursor();

	// the left button handles the interface
	if(button==0)
	for(int i=objects->size()-1;i>=0;--i)
		if((*objects)[i]->hit(mousecursor->getX(), mousecursor->getY())){
			if(current_focus)blur(current_focus);
				focus((*objects)[i]);
			press((*objects)[i]);
			return;
		}
				
   if(current_focus)blur(current_focus);
}

void	InterfaceHandler::onMouseUp(int button){
	// The focus stays until clicked on another object
	// Release comes as soon as mouse is released, object is stored in current_focus
	
	MouseCursor* mousecursor = Globals::getGlobals()->engine->getMouseHandler()->getMouseCursor();

	if(button==0)
	    if(current_focus)release(current_focus);
}

