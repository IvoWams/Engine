#include <collision/algorithms/CASphereLine.h>
#include <global/Tools.h>

CASphereLine::CASphereLine(CollisionSphere* _sphere, CollisionLine* _line){
	sphere = _sphere;
	line = _line;
}

CASphereLine::~CASphereLine(){}

bool    CASphereLine::checkCollision(){
	// Todo: implement closest point on line algorithm
	Vector distancevector;
	divVector(distancevector, *sphere->getCenter(), *line->getPoint1());
	return lengthVector(distancevector) < sphere->getSize();
}

void    CASphereLine::paint(){}