#include <keyframe/KeyFrameVectorProperty.h>

KeyFrameVectorProperty::KeyFrameVectorProperty(Vector* _subject, double x, double y, double z) : KeyFrameProperty(){
    subject = _subject;
    goal = new Vector(x, y, z);
}

KeyFrameVectorProperty::~KeyFrameVectorProperty(){
    delete goal;
}

void	KeyFrameVectorProperty::animate(double fraction){
    subject->x += (fraction * (goal->x - subject->x));
    subject->y += (fraction * (goal->y - subject->y));
    subject->z += (fraction * (goal->z - subject->z));
}

void	KeyFrameVectorProperty::finish(){
    subject->x = goal->x;
    subject->y = goal->y;
    subject->z = goal->z;
}    
