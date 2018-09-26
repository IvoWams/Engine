using namespace std;

#ifndef KEYFRAMEPROPERTY_H
#define KEYFRAMEPROPERTY_H

class KeyFrameProperty {
    private:
    public:
    	// KeyFrameProperty dictates a single property of an object to change
    	// during an interval. Classes implementing this base class, implement the
    	// change needed for animating the property they implement for.
    	
        virtual void	animate(double);	// Apply a fraction of the animation
        virtual void	finish();			// Apply the end of animation
};
    
#endif
