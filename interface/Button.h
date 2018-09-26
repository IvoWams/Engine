// Simple button interface

using namespace std;

#ifndef BUTTON_H
#define BUTTON_H

#include <interface/InterfaceObject.h>
#include <interface/Label.h>
#include <global/Color.h>
#include <global/GlobalValues.h>

class Button : public InterfaceObject {
	private:
		Label*		label;

	public:
		Button(double, double, double, double, Font*);
		Button(Button*);
		~Button();

		Label*		getLabel(){	return label; }

		void	paint();
};

#endif
