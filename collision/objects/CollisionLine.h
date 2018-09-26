using namespace std;

#ifndef COLLISIONLINE_H
#define COLLISIONLINE_H

#include <collision/objects/CollisionObject.h>

class CollisionLine : public CollisionObject {
	private:
	public:
		// See CollisionSphere for more info
		virtual Vector* getPoint1();
		virtual Vector* getPoint2();
};

#endif