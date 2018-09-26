#include <texture/TextureHandler.h>
#include <string.h>

TextureHandler::TextureHandler(){
	textures = new vector<Texture*>;
	glGenTextures(MAX_TEXTURES, &genlist[0]);
}

TextureHandler::~TextureHandler(){
	// Forcibly remove all textures
	for(int i=0;i<textures->size();++i)
		delete (*textures)[i];
	delete textures;
}

Texture*	TextureHandler::getTexture(const string& fname){
	for(int i=0;i<textures->size();++i)
		if((*textures)[i]->filename == fname){
			(*textures)[i]->incRef();
			return (*textures)[i];
		}

	// Find first free texture gl ref (linear search pattern)
    GLuint count = 0;
    if(textures->size()>0){
        while((*textures)[count]->glref==count && count != textures->size()-1)count++;
        count++;
	}
	
	// Create new texture
	Texture* texture = new Texture(fname, count);
	if(count==textures->size()){
        textures->push_back(texture);
    }else{
        textures->insert(textures->begin()+count, texture);
    }	   

	texture->incRef();
	return texture;
}

void		TextureHandler::freeTexture(const string& fname){
	for(int i=0;i<textures->size();++i)
		if((*textures)[i]->filename == fname){
			(*textures)[i]->decRef();
			if(!(*textures)[i]->hasRef()){
				delete (*textures)[i];
				textures->erase(textures->begin()+i);                
			}
		}
}

