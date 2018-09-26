using namespace std;

// A SINGLE PROPERTY FOR A SINGLE BAR

#ifndef KEYFRAMEBAR_H
#define KEYFRAMEBAR_H

// Chronologically holds the keyframeproperty objects

#include <global/RootObject.h>
#include <keyframe/KeyFrameProperty.h>
#include <map>

class KeyFrameBar {
	private:
		RootObject*							subject;
		map<double, KeyFrameProperty*>*		keyframemap;

	public:
		KeyFrameBar(RootObject*);
		~KeyFrameBar();
		
		RootObject*						getSubject(){	 return subject; }
		map<double, KeyFrameProperty*>*	getProperties(){ return keyframemap; }

		void		setProperty(double, KeyFrameProperty*);
		void		proceed(double, double);	// plays from x to y
};

#endif
