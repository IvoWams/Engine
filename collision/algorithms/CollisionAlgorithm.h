using namespace std;

#ifndef COLLISIONALGORITHM_H
#define COLLISIONALGORITHM_H

#include <collision/objects/CollisionObject.h>

class CollisionAlgorithm {
	private:
	public:
		CollisionAlgorithm();
		virtual ~CollisionAlgorithm();
		
		// Only thing an collisionalgorithm needs to implement is a function
		// that returns if objects are colliding or not
		virtual bool    checkCollision();
		virtual void    paint();
};

#endif