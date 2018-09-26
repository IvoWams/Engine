#include <input/InputHandler.h>

InputHandler::InputHandler(){
	keybindings = new vector<KeyBind*>;
	listeners = new vector<InputListener*>;
}

InputHandler::~InputHandler(){
	delete(listeners);
}

void	InputHandler::addListener(InputListener* _inputlistener){
	listeners->push_back(_inputlistener);
}

void	InputHandler::delListener(InputListener* _inputlistener){
	for(int i=0;i<listeners->size();++i)
		if((*listeners)[i]==_inputlistener)
			listeners->erase(listeners->begin()+i);
}

void	InputHandler::addBind(int code, int value){
	keybindings->push_back(new KeyBind(code, value));
}

void	InputHandler::delBind(int code){
	for(int i=0;i<keybindings->size();++i)
		if((*keybindings)[i]->getCode() == code){
			KeyBind* todelete = (*keybindings)[i];
			keybindings->erase(keybindings->begin()+i);
			delete(todelete);
		}
}

void	InputHandler::keyUp(int code){
	// Notify users on key event
	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onKeyUp(code);
		
	// Notify users on binding event
	for(int i=0;i<keybindings->size();++i)
		if((*keybindings)[i]->getCode() == code && keymap[code])
			for(int j=0;j<listeners->size();++j)
				(*listeners)[j]->onKeybind((*keybindings)[i]->getValue()+1000);	// Release code is inc 1000

	keymap[code]=false;
}

void	InputHandler::keyDown(int code){
	// Notify users on key event
	for(int i=0;i<listeners->size();++i)
		(*listeners)[i]->onKeyDown(code);
		
	// Notify users on key binding event
	for(int i=0;i<keybindings->size();++i)
		if((*keybindings)[i]->getCode() == code && !keymap[code])
			for(int j=0;j<listeners->size();++j)
				(*listeners)[j]->onKeybind((*keybindings)[i]->getValue());

	keymap[code]=true;
}
