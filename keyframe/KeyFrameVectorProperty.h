using namespace std;

#ifndef KEYFRAMEVECTORPROPERTY_H
#define KEYFRAMEVECTORPROPERTY_H

#include <keyframe/KeyFrameProperty.h>
#include <global/Vector.h>

// Defines the transition calculation of a vector

class KeyFrameVectorProperty : public KeyFrameProperty {
    private:
    	Vector*			subject;	// The vector that is animated
    	Vector*			goal;		// The value the subject must reach

    public:
        KeyFrameVectorProperty(Vector*, double, double, double);
        ~KeyFrameVectorProperty();
        
        virtual void	animate(double);
        virtual void	finish();
};
    
#endif
