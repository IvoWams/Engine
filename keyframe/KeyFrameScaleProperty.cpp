#include <keyframe/KeyFrameScaleProperty.h>

KeyFrameScaleProperty::KeyFrameScaleProperty(RootObject* object, double x, double y, double z)
                     : KeyFrameVectorProperty(object->getScale(), x, y, z){}
					    
KeyFrameScaleProperty::~KeyFrameScaleProperty(){}
