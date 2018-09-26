#include <global/Vector.h>

Vector::Vector(){
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(double _x, double _y, double _z){
	x = _x;
	y = _y;
	z = _z;
}

/*
Vector::Vector(Vector* original){
	x = original->x;
	y = original->y;
	z = original->z;
}
*/

Vector::~Vector(){}

double	Vector::getLength(){
	return sqrt( x*x + y*y + z*z );
}
