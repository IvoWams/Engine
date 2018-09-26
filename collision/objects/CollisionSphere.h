using namespace std;

#ifndef COLLISIONSPHERE_H
#define COLLISIONSPHERE_H

// Contains data for using a sphere in collision detection

#include <collision/objects/CollisionObject.h>
#include <global/Vector.h>

class CollisionSphere : public CollisionObject {
	private:
	public:
		// This is an abstract class
		// Objects implementing sphere data for collision detection need the
		// following methods:

		virtual Vector* getCenter();
		virtual double  getSize();
};

#endif