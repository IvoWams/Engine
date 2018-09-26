// Generic Trigger Listening Template

using namespace std;

#include <interface/InterfaceObject.h>

#ifndef INTERFACELISTENER_H
#define INTERFACELISTENER_H

class InterfaceListener {
	private:
	public:        
		InterfaceListener();
		virtual	~InterfaceListener();

		virtual void    onMouseOver(InterfaceObject*);
		virtual void    onMouseOut(InterfaceObject*);
		virtual void	onFocus(InterfaceObject*);
		virtual void	onBlur(InterfaceObject*);
		virtual void	onPress(InterfaceObject*);
		virtual void	onRelease(InterfaceObject*);
		virtual void    onChange(InterfaceObject*);
};

#endif
