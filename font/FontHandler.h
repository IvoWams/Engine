using namespace std;

#ifndef FONTHANDLER_H
#define FONTHANDLER_H

#include <vector>
#include <string>
#include <font/Font.h>

class FontHandler {
	private:
		vector<Font*>*	fonts;

	public:
		FontHandler();
		~FontHandler();

		Font*			getFont(const string&, /* int, */ int);
		void			freeFont(const string&);
		
		vector<Font*>*	getFonts(){ return fonts; }
};

#endif
