using namespace std;

// A pane thats draggable with mouse (-handler)

#include <main/MainEngine.h>
#include <interface/Pane.h>
#include <input/MouseListener.h>
#include <interface/InterfaceListener.h>

#ifndef DRAGPANE_H
#define DRAGPANE_H

class MainEngine;

class DragPane : public Pane,
				 public MouseListener,
				 public InterfaceListener {

	private:
		MainEngine*	engine;
		bool		dragging;

	public:
		DragPane(double, double, double, double);
		~DragPane();

		virtual void	onMouseMove(double, double);
		virtual void 	onPress(InterfaceObject*);
		virtual void	onRelease(InterfaceObject*);
};

#endif
