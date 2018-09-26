using namespace std;

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <gl/gl.h>
#include <gl/glu.h>
// #include <sdl/sdl.h>
// #include <sdl/sdl_image.h>

class Texture {
	private:
		// Number of handler references
		int				refcount;

	public:
		Texture(const string&, GLuint);
		~Texture();

		// Texture identifier, as a filename
		string			filename;

		// Image properties, deprecated
		int				width;
		int				height;
		int				size;	// 2^size

		// The ID of the texture
		bool			available;		// flag
		GLuint			glref;

		void			incRef(){ refcount++; }
		void			decRef(){ refcount--; }
		bool			hasRef(){ return refcount>0; }
};

#endif
