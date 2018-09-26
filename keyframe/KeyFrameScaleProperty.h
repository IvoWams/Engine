using namespace std;

#ifndef KEYFRAMESCALEPROPERTY_H
#define KEYFRAMESCALEPROPERTY_H

#include <keyframe/KeyFrameVectorProperty.h>
#include <global/RootObject.h>

class KeyFrameScaleProperty : public KeyFrameVectorProperty {
    private:
    public:
        KeyFrameScaleProperty(RootObject*, double, double, double);
        ~KeyFrameScaleProperty();
};    

#endif
