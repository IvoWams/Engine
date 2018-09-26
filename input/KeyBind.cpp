#include <input/KeyBind.h>

KeyBind::KeyBind(int _code, int _value){
	code = _code;
	value = _value;
}

KeyBind::KeyBind(KeyBind* original){
	code = original->getCode();
	value = original->getValue();
}

KeyBind::~KeyBind(){}

int		KeyBind::getCode(){
	return code;
}

int		KeyBind::getValue(){
	return value;
}
