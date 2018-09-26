using namespace std;

#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

class Vector {
	private:
		
	public:
		double x;
		double y;
		double z;

		// Basic constructor
		Vector();
		Vector(double, double, double);
		~Vector();

		double	getLength();			// |vector|
	
};

#endif
