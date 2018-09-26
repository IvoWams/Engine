using namespace std;

// Manages textures by creating a handler around it counting references to the texture
// Could be done with a template class

#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <vector>
#include <texture/Texture.h>
#include <gl/gl.h>

#define MAX_TEXTURES 255

class TextureHandler {
	private:
//		string				directory;
		vector<Texture*>*	textures;
		GLuint				genlist[MAX_TEXTURES];

	public:
		TextureHandler();
		~TextureHandler();

		Texture*	getTexture(const string& fname);
		void		freeTexture(const string& fname);
		
//		const string&	getTextureDir(){ return directory; }
//		void			setTextureDir(const string& dir){ directory = dir; }
		
		// Debug:
		vector<Texture*>*	getTextures(){ return textures; }
};

#endif
