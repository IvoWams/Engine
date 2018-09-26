using namespace std;

#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include <collision/CollisionListener.h>
#include <collision/CollisionPair.h>
#include <vector>

class CollisionHandler {
	private:
		vector<CollisionListener*>* listeners;
		
		// Pairs of objects that can trigger collisions
		vector<CollisionPair*>*		pairs;
		
		// Pairs of objects that have just been triggered, and must wait before their collision is worn out
		vector<CollisionPair*>*     ignorepairs;
		
	public:
		CollisionHandler();
		~CollisionHandler();
		
		void    addListener(CollisionListener*);
		void    delListener(CollisionListener*);
		bool    hasListener(CollisionListener*);
		
		void    addPair(CollisionAlgorithm*, CollisionObject*, CollisionObject*);
		void    delPairsWith(CollisionObject*);
		
		vector<CollisionPair*>*     getPairs(){ return pairs; }
		
		void    checkCollisions();
		void    paint();
};

#endif