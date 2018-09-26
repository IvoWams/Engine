#include <collision/algorithms/CASphereSphere.h>
#include <global/Tools.h>

CASphereSphere::CASphereSphere(CollisionSphere* _sphere1, CollisionSphere* _sphere2){
	sphere1 = _sphere1;
	sphere2 = _sphere2;
}

CASphereSphere::~CASphereSphere(){}

bool CASphereSphere::checkCollision(){
	Vector  distancevector;
	divVector(distancevector, *sphere1->getCenter(), *sphere2->getCenter());
	return lengthVector(distancevector) < sphere1->getSize() + sphere2->getSize();
}

void    CASphereSphere::paintYCircle(const Vector& center, double size){
	int segments = 30;

	glColor4f(1,0,0, 0.1);
	glTranslatef(center.x, center.y, center.z);

	glBegin(GL_POLYGON);

	for(int i=0;i<segments;i++){
		glVertex3f( sin(i*2*3.141592654/segments)* size, cos(i*2*3.141592654/segments)* size, 0);
		glVertex3f( sin((i+1)*2*3.141592654/segments)* size, cos((i+1)*2*3.141592654/segments)* size, 0);
	}

	glEnd();
}

void    CASphereSphere::paint(){
	glPushMatrix();
	glLoadIdentity();

	paintYCircle(*sphere1->getCenter(), sphere1->getSize());
	paintYCircle(*sphere2->getCenter(), sphere2->getSize());

	glPopMatrix();
}


