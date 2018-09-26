#include <keyframe/KeyFrameBar.h>

KeyFrameBar::KeyFrameBar(RootObject* _subject){
	subject = _subject;
	keyframemap = new map<double, KeyFrameProperty*>;
}

KeyFrameBar::~KeyFrameBar(){
    for(int i=0;i<keyframemap->size();++i)
    	delete (*keyframemap)[i];
	delete keyframemap;
}

void	KeyFrameBar::setProperty(double time, KeyFrameProperty* property){
	// create pair of time and property, insert it where timer becomes smaller (lower_bound)
	keyframemap->insert(keyframemap->lower_bound(time), make_pair(time, property));
}

void	KeyFrameBar::proceed(double start, double end){
    if(end == start)return;	// No action if no time passed
    
	if(!keyframemap->empty()){
		double time					= keyframemap->begin()->first;
		KeyFrameProperty* property	= keyframemap->begin()->second;

		if(time>end){
			// If the keyframe finishes in the future, apply only a piece of the keyframe properties
			property->animate((end - start)/(time - start));
		}else{
		    property->finish();
		    delete property;
		    
		    keyframemap->erase(keyframemap->begin());
		    proceed(time, end);	// Animate remaining frame window
		}
	}	
}
