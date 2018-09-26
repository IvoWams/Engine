using namespace std;

#ifndef KEYBIND_H
#define KEYBIND_H

class KeyBind {
	private:
		int		code;
		int		value;

	public:
		KeyBind(int, int);
		KeyBind(KeyBind*);
		~KeyBind();

		int		getCode();
		int		getValue();
};

#endif
