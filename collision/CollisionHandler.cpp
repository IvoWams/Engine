#include <collision/CollisionHandler.h>

CollisionHandler::CollisionHandler(){
	pairs = new vector<CollisionPair*>;
//	ignorepairs = new vector<CollisionPair*>;
	listeners = new vector<CollisionListener*>;
}

CollisionHandler::~CollisionHandler(){
	delete listeners;
//	delete ignorepairs;
	delete pairs;
}

void    CollisionHandler::addListener(CollisionListener* listener){
	listeners->push_back(listener);
}

void    CollisionHandler::delListener(CollisionListener* listener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==listener)
		    listeners->erase(listeners->begin()+i);
}

bool    CollisionHandler::hasListener(CollisionListener* listener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==listener)
			return true;
	return false;
}

void    CollisionHandler::addPair(CollisionAlgorithm* algorithm, CollisionObject* object_A, CollisionObject* object_B){
	CollisionPair* pair = new CollisionPair(algorithm, object_A, object_B);
	pairs->push_back(pair);
}

void    CollisionHandler::delPairsWith(CollisionObject* object){
	for(int i=0;i<pairs->size();++i)
	    if((*pairs)[i]->getObjectA() == object || (*pairs)[i]->getObjectB() == object){
			CollisionPair* pair = (*pairs)[i];
			pairs->erase(pairs->begin()+i);
			delete pair->getAlgorithm();
			delete pair;
			i--;
		}
/*
	for(int i=0;i<ignorepairs->size();++i)
	    if((*ignorepairs)[i]->getObjectA() == object || (*pairs)[i]->getObjectB() == object){
			CollisionPair* pair = (*ignorepairs)[i];
			ignorepairs->erase(ignorepairs->begin()+i);
			delete pair;
			i--;
		}
*/
}

void    CollisionHandler::checkCollisions(){
	// First check if there are ignored pairs that can be put back into the normal list

/*
	for(int i=0;i<ignorepairs->size();++i)
	    if(!(*ignorepairs)[i]->getAlgorithm()->checkCollision()){
			pairs->push_back((*ignorepairs)[i]);            // add ignored pair to normal list
			ignorepairs->erase(ignorepairs->begin()+i);     // remove from ignore list
			i--;    // readjust iterator
		}
*/
	// Check collisions:
	for(int i=0;i<pairs->size();++i)
	    if((*pairs)[i]->getAlgorithm()->checkCollision()){
            (*pairs)[i]->getAlgorithm()->paint();
	        for(int j=0;j<listeners->size();++j)
	            (*listeners)[j]->onCollision((*pairs)[i]);      // sound the alarm
/*
			ignorepairs->push_back((*pairs)[i]);
			pairs->erase(pairs->begin()+i);
			i--;    // readjust iterator
*/
		}
}

void    CollisionHandler::paint(){
	for(int i=0;i<pairs->size();++i)
	    (*pairs)[i]->getAlgorithm()->paint();
}