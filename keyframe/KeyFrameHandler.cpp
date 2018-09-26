#include <keyframe/KeyFrameHandler.h>
#include <typeinfo>
#include <fstream>

KeyFrameHandler::KeyFrameHandler(){
	listeners = new vector<KeyFrameListener*>;
	keyframebars = new vector<KeyFrameBar*>;
	last_time = 0;
}

KeyFrameHandler::~KeyFrameHandler(){
	delete keyframebars;
	delete listeners;
}

// Listener management:
void	KeyFrameHandler::addListener(KeyFrameListener* _listener){
	listeners->push_back(_listener);
}

void	KeyFrameHandler::delListener(KeyFrameListener* _listener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_listener)
			listeners->erase(listeners->begin()+i);
}

bool	KeyFrameHandler::hasListener(KeyFrameListener* _listener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_listener)
			return true;
	return false;
}

void	KeyFrameHandler::setProperty(RootObject* subject, double time, KeyFrameProperty* property){
	// Finds the keyframebar of typeid property and of rootobject
	// Either insert property or create a new keyframebar and insert it there

	for(int i=0;i<keyframebars->size();++i){
	    KeyFrameBar* keyframebar = (*keyframebars)[i];
	    KeyFrameProperty* firstproperty = keyframebar->getProperties()->begin()->second;	// Empty containers wouldnt exist here

	    if(keyframebar->getSubject() == subject &&			// Is this bar targeting our rootobject?
	       typeid(*firstproperty) == typeid(*property)){	// Is this bar containing the same property objects?
	       		// insert here
	       		keyframebar->setProperty(time, property);
				return;
		}
	}

	// At this point, no valid keyframebar is found
	// So create it and insert the property
	KeyFrameBar* keyframebar = new KeyFrameBar(subject);
	keyframebars->push_back(keyframebar);
	keyframebar->setProperty(time, property);
}

bool	KeyFrameHandler::hasKeyFrames(RootObject* rootobject){
	// returns true if the given object has any scheduled animation
	for(int i=0;i<keyframebars->size();++i)
		if((*keyframebars)[i]->getSubject() == rootobject)
			return (*keyframebars)[i]->getProperties()->size()>0;
	return false;
}

void	KeyFrameHandler::delKeyFrameBarWith(RootObject* rootobject){
	// remove keyframebar assign to rootobject
	for(int i=0;i<keyframebars->size();++i)
		if((*keyframebars)[i]->getSubject()==rootobject){
			delete (*keyframebars)[i];
			keyframebars->erase(keyframebars->begin()+i);
		}
}

/*
void	KeyFrameHandler::clean(){	// Removes all objects and attached bars that have no keyframes
									// Code combi of the two methods above for speed

	fstream fout("kfh.log", ios::out | ios::app);
	int count = 0;

	fout << "*** New Run ***\n\n";

	// For each keyframebar known
	for(int i=0;i<keyframebars->size();++i){

		fout << "Keyframebar " << i << "\n";
		RootObject* object = (*keyframebars)[i]->getSubject();
		fout << "Attached object " << object << "\n";
		fout << "Properties queued " << (*keyframebars)[i]->getProperties()->size() << "\n";

		// If this bar contains no properties ie frames
		if((*keyframebars)[i]->getProperties()->size()==0){

			// Free from memory
			delete (*keyframebars)[i];

			// Remove from bar
			keyframebars->erase(keyframebars->begin()+i);

			i--;

			count++;

		} else {
			fout << "Deadline first " << (*keyframebars)[i]->getProperties()->begin()->first << "\n";
		}
		fout << "\n";
	}
	fout << "\n\n";
	fout.close();
}
*/

void	KeyFrameHandler::setPosition(RootObject* rootobject, double time, double x, double y, double z){
    setProperty(rootobject, time, new KeyFramePositionProperty(rootobject, x, y, z));
}

void	KeyFrameHandler::setRotation(RootObject* rootobject, double time, double x, double y, double z){
    setProperty(rootobject, time, new KeyFrameRotationProperty(rootobject, x, y, z));
}

void	KeyFrameHandler::setScale(RootObject* rootobject, double time, double x, double y, double z){
    setProperty(rootobject, time, new KeyFrameScaleProperty(rootobject, x, y, z));
}

void	KeyFrameHandler::setColor(RootObject* rootobject, double time, double R, double G, double B){
    setProperty(rootobject, time, new KeyFrameColorProperty(rootobject, R, G, B));
}

void	KeyFrameHandler::setAlpha(RootObject* rootobject, double time, double A){
	setProperty(rootobject, time, new KeyFrameAlphaProperty(rootobject, A));
}

void	KeyFrameHandler::tick(double sec){
	double current_time = last_time + sec;

	for(int i=0;i<keyframebars->size();++i)
//		if((*keyframebars)[i]->getProperties()->size()>0){
			// If this frame has something to proceed to, do it
			(*keyframebars)[i]->proceed(last_time, current_time);
//		} else {
			// Or else remove it
//			keyframebars->erase(keyframebars->begin()+i);
//			delete (*keyframebars)[i];
//			i--;
//		}

	last_time = current_time;

	// Clean empty keyframebars? Could be bad for performance
//	clean();

	for(int i=0;i<keyframebars->size();++i)
		if((*keyframebars)[i]->getProperties()->size()==0){
			KeyFrameBar* bar = (*keyframebars)[i];
			keyframebars->erase(keyframebars->begin() + i);
			delete bar;
			i--;
		}

}
