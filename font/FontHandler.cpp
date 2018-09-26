#include <font/FontHandler.h>
#include <string.h>

FontHandler::FontHandler(){
    fonts = new vector<Font*>;
}

FontHandler::~FontHandler(){
    for(int i=0;i<fonts->size();++i)
        delete (*fonts)[i];
    delete fonts;
}    

Font*   FontHandler::getFont(const string& fname, /* int texture_size, */ int glyph_size){
	char* buffer = (char*)malloc(255);
	sprintf(buffer, "%s %d", fname.data(), /* texture_size, */ glyph_size);
	string texhandle = buffer;
	free(buffer);
	
	
    for(int i=0;i<fonts->size();++i)
    	if((*fonts)[i]->getTexture()->filename == texhandle)return (*fonts)[i];				// return it
	
    Font* font = new Font(fname, glyph_size);
    
    fonts->push_back(font);
    return font;
}

