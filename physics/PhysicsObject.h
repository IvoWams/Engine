// Physics object
// Extend this object to enable your object with the following:

// - Acceleration
// - Friction Force
// - Centrifugal Force
// - Rotational Force
// - Gravity
// - Impulse

using namespace std;

#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <global/RootObject.h>
#include <global/Tools.h>
#include <math.h>

class PhysicsObject : public RootObject {
	protected:
		Vector*     prevposition;
		Vector*		motion;			// Current movement vector or velocity

		Vector*		acceleration;
		Vector*		friction;
		Vector*		centrifugal;
		Vector*		rotational;
		Vector*		gravity;
		Vector*		impulse;

		double		speed;			// resulting speed
		double		mass;
		double		material;		// friction coefficient

	public:
		PhysicsObject();
		~PhysicsObject();

		// Properties
		void			setMass(double);
		double			getMass(){ return mass; }

		void			setMaterial(double);
		double			getMaterial(){ return material; }


		double			getSpeed(){ return speed; }

		// Globally set by the handler:
		void			setGravity(double, double, double);			// Set gravity vector
		Vector*			getGravity(){ return gravity; }

		void            setMotion(double, double, double);
		Vector*			getMotion(){ return motion; }				// Resulting current motion vector, or velocity

		void	setAcceleration(double, double, double);			// accelerate to (for steering ea)
		void	setImpulse(double, double, double);					// one sided elastic collision

		Vector*	getAcceleration(){return acceleration;}
		Vector*	getFriction(){return friction;}
		
		Vector* getPrevPosition(){ return prevposition; }          // returns position of object before last applied motion vector

		// calculations
		// overwrite for alternate calculations / laws

		void	calcAcceleration();
		void	calcFriction();
		void	calcCentrifugal();
		void	calcRotational();
		void	calcImpulse();

		void	calcMotion(double);
		
		void    paint();
};

#endif
