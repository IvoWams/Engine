using namespace std;

#ifndef CASPHERESPHERE_H
#define CASPHERESPHERE_H

#include <collision/algorithms/CollisionAlgorithm.h>
#include <collision/objects/CollisionSphere.h>
// Sphere vs Sphere (or bounding sphere) collision detection algorithm

class CASphereSphere : public CollisionAlgorithm {
	private:
		CollisionSphere*    sphere1;
		CollisionSphere*    sphere2;
		
		
		void	paintYCircle(const Vector&, double);
		
	public:
		CASphereSphere(CollisionSphere*, CollisionSphere*);
		virtual ~CASphereSphere();
		
		virtual bool    checkCollision();
		virtual void    paint();
};

#endif