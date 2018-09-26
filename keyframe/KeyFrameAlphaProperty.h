using namespace std;

#ifndef KEYFRAMEALPHAPROPERTY_H
#define KEYFRAMEALPHAPROPERTY_H

#include <keyframe/KeyFrameProperty.h>
#include <global/RootObject.h>
#include <global/Color.h>

class KeyFrameAlphaProperty : public KeyFrameProperty {
    private:
        Color*	subject;
		double	goal;
    public:
    	KeyFrameAlphaProperty(RootObject*, double);
    	~KeyFrameAlphaProperty();
    	
    	virtual void	animate(double);
    	virtual void	finish();
};    

#endif
