using namespace std;

#ifndef CASPHERELINE_H
#define CASPHERELINE_H

#include <collision/algorithms/CollisionAlgorithm.h>
#include <collision/objects/CollisionSphere.h>
#include <collision/objects/CollisionLine.h>

class CASphereLine : public CollisionAlgorithm {
	private:
		CollisionSphere*	sphere;
		CollisionLine*      line;
	public:
		CASphereLine(CollisionSphere*, CollisionLine*);
		virtual ~CASphereLine();
		
		virtual bool    checkCollision();
		virtual void    paint();
};
#endif