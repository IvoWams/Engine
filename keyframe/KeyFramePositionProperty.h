using namespace std;

#ifndef KEYFRAMEPOSITIONPROPERTY_H
#define KEYFRAMEPOSITIONPROPERTY_H

#include <keyframe/KeyFrameVectorProperty.h>
#include <global/RootObject.h>

class KeyFramePositionProperty : public KeyFrameVectorProperty {
    private:
    public:
        KeyFramePositionProperty(RootObject*, double, double, double);
        ~KeyFramePositionProperty();
};    

#endif
