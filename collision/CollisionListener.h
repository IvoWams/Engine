using namespace std;

#ifndef COLLISIONLISTENER_H
#define COLLISIONLISTENER_H

#include <collision/CollisionPair.h>

class CollisionListener {
	public:
		virtual void    onCollision(CollisionPair*);
};

#endif