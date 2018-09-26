using namespace std;

#ifndef KEYFRAMEROTATIONPROPERTY_H
#define KEYFRAMEROTATIONPROPERTY_H

#include <keyframe/KeyFrameVectorProperty.h>
#include <global/RootObject.h>

class KeyFrameRotationProperty : public KeyFrameVectorProperty {
    private:
    public:
        KeyFrameRotationProperty(RootObject*, double, double, double);
        ~KeyFrameRotationProperty();
};    

#endif
