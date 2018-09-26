#include <global/RootObject.h>

RootObject::RootObject(){
	position = new Vector(0,0,0);
	rotation = new Vector(0,0,0);
	scale    = new Vector(1,1,1);
	color	 = new Color(0,0,0,0);
	
	flat	 = false;
	visible  = true;
	enabled  = true;
	
	order = 0;
}

RootObject::~RootObject(){
    delete color;
	delete scale;
	delete rotation;
	delete position;
}

void		RootObject::setPosition(const Vector& vector){
	position->x = vector.x;
	position->y = vector.y;
	position->z = vector.z;
}

void		RootObject::setPosition(double _x, double _y, double _z){
	position->x = _x;
	position->y = _y;
	position->z = _z;
}

void 		RootObject::incPosition(double _x, double _y, double _z){
	position->x += _x;
	position->y += _y;
	position->z += _z;
}

void 		RootObject::setRotation(const Vector& vector){
	rotation->x = vector.x;
	rotation->y = vector.y;
	rotation->z = vector.z;
}

void		RootObject::setRotation(double _x, double _y, double _z){
	rotation->x = _x;
	rotation->y = _y;
	rotation->z = _z;
}

void 		RootObject::incRotation(double _x, double _y, double _z){
	rotation->x += _x;
	rotation->y += _y;
	rotation->z += _z;
}

void		RootObject::setScale(const Vector& vector){
	scale->x = vector.x;
	scale->y = vector.y;
	scale->z = vector.z;
}

void		RootObject::setScale(double _x, double _y, double _z){
	scale->x = _x;
	scale->y = _y;
	scale->z = _z;
}

void 		RootObject::incScale(double _x, double _y, double _z){
	scale->x += _x;
	scale->y += _y;
	scale->z += _z;
}

void		RootObject::setColor(const Color& _color){
    color->R = _color.R;
    color->G = _color.G;
    color->B = _color.B;
    color->A = _color.A;
}

void		RootObject::setColor(double _R, double _G, double _B, double _A){
    color->R = _R;
    color->G = _G;
    color->B = _B;
    color->A = _A;
}        

void		RootObject::incColor(double _R, double _G, double _B, double _A){
    color->R += _R;
    color->G += _G;
    color->B += _B;
    color->A += _A;
}    

void        RootObject::paint(){}
