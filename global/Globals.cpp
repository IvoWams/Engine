#include <global/Globals.h>

Globals* Globals::globals = NULL;

Globals::Globals(){
	engine = new MainEngine();
}
Globals::~Globals(){
	delete engine;
}

Globals* Globals::getGlobals(){
	if(!globals){ globals = new Globals; }
	return globals;
}
