#include <keyframe/KeyFrameColorProperty.h>

KeyFrameColorProperty::KeyFrameColorProperty(RootObject* object, double R, double G, double B/* , double A */){
    subject = object->getColor();
    goal = new Color(R, G, B/* , A */);
}

KeyFrameColorProperty::~KeyFrameColorProperty(){
    delete goal;
}

void	KeyFrameColorProperty::animate(double fraction){
    // All linear animations
    subject->incColor( 
		fraction * (goal->R - subject->R),
        fraction * (goal->G - subject->G),
        fraction * (goal->B - subject->B),
        0
//        fraction * (goal->A - subject->A)
	);
}

void	KeyFrameColorProperty::finish(){
	subject->setColor(
		goal->R, goal->G, goal->B /*, goal->A */
	);
}            
