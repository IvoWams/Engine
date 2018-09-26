#include <interface/DragPane.h>
#include <global/Globals.h>

DragPane::DragPane(double x, double y, double w, double h) : Pane(x,y,w,h){
	dragging = false;
	engine = Globals::getGlobals()->engine;

	// Subscribe this pane, if it isnt already...
	if(!engine->getMouseHandler()->hasListener(this))engine->getMouseHandler()->addListener(this);
	if(!engine->getInterfaceHandler()->hasListener(this))engine->getInterfaceHandler()->addListener(this);
}

DragPane::~DragPane(){
	// Unsubscribe this pane, if it isnt already...
	if(engine->getMouseHandler()->hasListener(this))engine->getMouseHandler()->delListener(this);
	if(engine->getInterfaceHandler()->hasListener(this))engine->getInterfaceHandler()->delListener(this);
}

void	DragPane::onMouseMove(double x, double y){
	if(dragging)replace(x,y);
	
	// might do this another way
	engine->getInterfaceHandler()->change(this);
}

void	DragPane::onPress(InterfaceObject* io){
	if(!dragging && this==io)dragging = true;
}

void	DragPane::onRelease(InterfaceObject* io){
	dragging=false;
}

