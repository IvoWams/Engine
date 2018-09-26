#include <input/MouseHandler.h>
#include <global/Globals.h>

MouseHandler::MouseHandler(){
	listeners = new vector<MouseListener*>;
	mousecursor = new MouseCursor(0,0);
	
	hidden = false;
	setBoundary(0,0,800,600);
}

MouseHandler::~MouseHandler(){
	delete(mousecursor);
	delete(listeners);
}

void	MouseHandler::addListener(MouseListener* _mouselistener){
	listeners->push_back(_mouselistener);
}

void	MouseHandler::delListener(MouseListener* _mouselistener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_mouselistener)
			listeners->erase(listeners->begin()+i);
}

bool	MouseHandler::hasListener(MouseListener* ml){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==ml)
			return true;
	return false;
}

void    MouseHandler::setMouse(double x, double y){
	mousecursor->setPosition(x, y);
//	mouseMove( mousecursor->getX() - x, mousecursor->getY() - y );
}

void    MouseHandler::resetBoundary(){
  	boundary_left = 0;
	boundary_right = Globals::getGlobals()->engine->getRenderer()->getWidth();
	boundary_top = 0;
	boundary_bottom = Globals::getGlobals()->engine->getRenderer()->getHeight();
}

void    MouseHandler::setBoundary(double left, double top, double right, double bottom){
	boundary_left = left;
	boundary_right = right;
	boundary_top = top;
	boundary_bottom = bottom;
}

void    MouseHandler::showMouse(bool show){
	hidden = !show;
}


void	MouseHandler::mouseMove(double x, double y){
	// prevent mouse from moving over boundaries
	if(mousecursor->getX()+x > boundary_right)x = boundary_right - mousecursor->getX();
	if(mousecursor->getX()+x < boundary_left)x = boundary_left - mousecursor->getX();
	if(mousecursor->getY()+y > boundary_bottom)y = boundary_bottom - mousecursor->getY();
	if(mousecursor->getY()+y < boundary_top)y = boundary_top - mousecursor->getY();

	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onMouseMove(x, y);

	mousecursor->onMouseMove(x, y);
}

void	MouseHandler::mouseDown(int btn){
	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onMouseDown(btn);
}

void	MouseHandler::mouseUp(int btn){
	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onMouseUp(btn);
}

void    MouseHandler::paint(){
	if(!hidden)mousecursor->paint();
}
