using namespace std;

#ifndef KEYFRAMECOLORPROPERTY_H
#define KEYFRAMECOLORPROPERTY_H

#include <keyframe/KeyFrameProperty.h>
#include <global/RootObject.h>
#include <global/Color.h>

class KeyFrameColorProperty : public KeyFrameProperty {
    private:
        Color*	subject;
        Color*	goal;
    public:
    	KeyFrameColorProperty(RootObject*, double, double, double);
    	~KeyFrameColorProperty();
    	
    	virtual void	animate(double);
    	virtual void	finish();
};    

#endif
