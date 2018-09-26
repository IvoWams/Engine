#include <keyframe/KeyFrameAlphaProperty.h>

KeyFrameAlphaProperty::KeyFrameAlphaProperty(RootObject* object, double A){
    subject = object->getColor();
    goal = A;
}

KeyFrameAlphaProperty::~KeyFrameAlphaProperty(){}

void	KeyFrameAlphaProperty::animate(double fraction){
    // All linear animations
    subject->incColor( 0, 0, 0, fraction * (goal - subject->A ) );

}

void	KeyFrameAlphaProperty::finish(){
	subject->setColor( subject->R, subject->G, subject->B, goal);
}            
