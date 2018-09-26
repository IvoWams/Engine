#include <global/Camera.h>

Camera::Camera(){
	position = new Vector(0,0,0);
	target   = new Vector(1,0,0);   // just look somewhere
}

Camera::~Camera(){
	delete position;
	delete target;
}

Vector*	Camera::getPosition(){
	return position;
}

Vector*	Camera::getTarget(){
	return target;
}
