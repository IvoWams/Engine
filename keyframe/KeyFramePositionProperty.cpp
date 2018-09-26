#include <keyframe/KeyFramePositionProperty.h>

KeyFramePositionProperty::KeyFramePositionProperty(RootObject* object, double x, double y, double z)
					    : KeyFrameVectorProperty(object->getPosition(), x, y, z){}
					    
KeyFramePositionProperty::~KeyFramePositionProperty(){}
