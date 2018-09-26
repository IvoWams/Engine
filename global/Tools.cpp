#include <global/Tools.h>
#include <iostream>

double	getAngle(const Vector& a, const Vector& b){
	Vector div;
	divVector(div, a, b);

	double distance = lengthVector(div);

	double angle = 0;
	double difangle = 0;

	angle = asin(div.y / distance) * (180/PI);
	if(div.x >= 0){
		angle = 90 - angle;
	} else {
		angle = 270 + angle;
	}

	return angle;
}

void	crossVector(Vector& target, const Vector& a, const Vector& b){
	target.x = (a.y*b.z)-(a.z*b.y);
	target.y = (a.z*b.x)-(a.x*b.z);
	target.z = (a.x*b.y)-(a.y*b.x);
}

void	divVector(Vector& target, const Vector& a, const Vector& b){
	target.x = a.x - b.x;
	target.y = a.y - b.y;
	target.z = a.z - b.z;
}

double	lengthVector(const Vector& a){
	return sqrt( (a.x*a.x)+(a.y*a.y)+(a.z*a.z) );
}

void	normalizeVector(Vector& a){
	double length = lengthVector(a);
	a.x = a.x/length;
	a.y = a.y/length;
	a.z = a.z/length;
}

void	getNormal(Vector& target, const Vector& a, const Vector& b, const Vector& c){
	Vector div1, div2, cross;
	divVector(div1, c, a);
	divVector(div2, b, a);
	crossVector(cross, div1, div2);
	normalizeVector(cross);
	target.x = cross.x;
	target.y = cross.y;
	target.z = cross.z;
}


void	paintRect(const Vector& a, const Vector& b, const Vector& c, const Vector& d){
	Vector normal;
	getNormal(normal, a, b, c);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3f(a.x, a.y, a.z);
	glVertex3f(b.x, b.y, b.z);
	glVertex3f(c.x, c.y, c.z);
	glVertex3f(d.x, d.y, d.z);
}

void	paintTria(const Vector& a, const Vector& b, const Vector& c){
	Vector normal;
	getNormal(normal, a, b, c);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3f(a.x, a.y, a.z);
	glVertex3f(b.x, b.y, b.z);
	glVertex3f(c.x, c.y, c.z);
}
