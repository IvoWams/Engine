// Class Pane
// Contains a collection of interface objects

#ifndef PANE_H
#define PANE_H

using namespace std;

#include <global/Color.h>
#include <interface/InterfaceObject.h>
#include <interface/InterfaceHandler.h>
#include <interface/InterfaceListener.h>

class Pane : public InterfaceObject {
	private:
		bool	show;
		bool	enabled;

		void 	vlak(double, double, double, double);

	public:
		Pane(double, double, double, double);
		~Pane();

		void	paint();
};

#endif
