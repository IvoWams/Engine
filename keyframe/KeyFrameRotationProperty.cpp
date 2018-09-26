#include <keyframe/KeyFrameRotationProperty.h>

KeyFrameRotationProperty::KeyFrameRotationProperty(RootObject* object, double x, double y, double z)
					    : KeyFrameVectorProperty(object->getRotation(), x, y, z){}
					    
KeyFrameRotationProperty::~KeyFrameRotationProperty(){}
