using namespace std;

#ifndef COLLISIONPAIR_H
#define COLLISIONPAIR_H

// Couples two objects with an algorithm

#include <collision/algorithms/CollisionAlgorithm.h>
#include <collision/objects/CollisionObject.h>

class CollisionPair {
	private:
		CollisionAlgorithm* algorithm;
		CollisionObject*	object_A;
		CollisionObject*	object_B;
		
	public:
		CollisionPair(CollisionAlgorithm*, CollisionObject*, CollisionObject*);
		~CollisionPair();
		
		CollisionAlgorithm* getAlgorithm(){ return algorithm; }
		CollisionObject* getObjectA(){ return object_A; }
		CollisionObject* getObjectB(){ return object_B; }

};

#endif