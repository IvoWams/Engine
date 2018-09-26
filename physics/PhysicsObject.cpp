#include <physics/PhysicsObject.h>
#include <global/GlobalValues.h>
#include <gl/gl.h>

PhysicsObject::PhysicsObject() : RootObject(){
	prevposition    = new Vector();
	motion			= new Vector();
	acceleration	= new Vector();
	friction		= new Vector();
	centrifugal		= new Vector();
	rotational		= new Vector();
	gravity			= new Vector();
	impulse			= new Vector();

	mass            = 0;
	material        = 0;
	speed			= 0;
}

PhysicsObject::~PhysicsObject(){
	delete motion;
	delete acceleration;
	delete friction;
	delete centrifugal;
	delete rotational;
	delete gravity;
	delete impulse;
}

void	PhysicsObject::setMass(double _mass){
	mass = _mass;
}

void	PhysicsObject::setMaterial(double _material){
	material = _material;
}

void	PhysicsObject::setGravity(double _x, double _y, double _z){
	gravity->x = _x;
	gravity->y = _y;
	gravity->z = _z;
}

void	PhysicsObject::setImpulse(double _x, double _y, double _z){
	impulse->x += _x;
	impulse->y += _y;
	impulse->z += _z;
}

void	PhysicsObject::setAcceleration(double _x, double _y, double _z){
	acceleration->x = _x;
 	acceleration->y = _y;
	acceleration->z = _z;
	
	// Ongeacht massa enzow
}

void    PhysicsObject::setMotion(double _x, double _y, double _z){
	motion->x = _x;
	motion->y = _y;
	motion->z = _z;
}

void	PhysicsObject::calcAcceleration(){
	// Already set
}

void	PhysicsObject::calcFriction(){
	// Calculate Friction, material == friction coefficient
	// This calculates a normal friction of an object against a surface
	// For example a vehicle class should change the coefficient if the vehicle
	// is moving in a forward direction or if it is drifting, etc...

//	double Ff	= material * mass;

	friction->x = -motion->x * material;
	friction->y = -motion->y * material;

	// Against the Z axis, there is only friction with air
//	friction.z = -motion.z * 0.01 * mass;
}

void	PhysicsObject::calcCentrifugal(){
	// Calculate Centrifugal Force
	// steerspeed = degree's / second
	// omtrek     = 360/steerspeed * speed;
	// radius == (360/steerspeed)speed / (2 pi)
	// diameter   = sqrt( PI/outline )
	// radius     = diameter/2
	// Fc         = mass * (speed * speed) / radius

/*
	double unitspeed = speed/unit;

	double radius = (360/steerspeed)*unitspeed / (2*PI);
	double Fc	 = mass * (unitspeed * unitspeed) / radius;
	double Fc_ang = 0;

	if(steeringleft) Fc_ang = heading+90;
	if(steeringright)Fc_ang = heading-90;

	if(Fc_ang!=0 && unitspeed > 0.01){
		circular->x = sin(Fc_ang * (PI/180)) * Fc/unit;
		circular->y = cos(Fc_ang * (PI/180)) * Fc/unit;
	} else {
		circular->x = 0;
		circular->y = 0;
	}
*/
}

void	PhysicsObject::calcRotational(){}


void	PhysicsObject::calcImpulse(){
	// No implementation
}

void	PhysicsObject::calcMotion(double unit){
	// Backup current position
	prevposition->x = position->x;
	prevposition->y = position->y;
	prevposition->z = position->z;

	// All time related vectors
	double x = (acceleration->x + friction->x + gravity->x)/unit;
	double y = (acceleration->y + friction->y + gravity->y)/unit;
	double z = (acceleration->z + friction->z + gravity->z)/unit;

	// Impulse is not really time related?? need to look up
	motion->x += x + impulse->x;
	motion->y += y + impulse->y;
	motion->z += z + impulse->z;

	// Now the position of the object has the motion/velocity vector added.
	// Divided by unit determines the amount the motion is applied based on the timeframe.

	position->x += (motion->x / unit);
	position->y += (motion->y / unit);
	position->z += (motion->z / unit);

	// Speed is the length of the motion vector
	speed = lengthVector(*motion);

	// Reset impulse
	impulse->x = 0;
	impulse->y = 0;
	impulse->z = 0;
}

void    PhysicsObject::paint(){
}

