#include <texture/Texture.h>

Texture::Texture(const string& _fname, GLuint _glref){
	filename = _fname;
	glref = _glref;
	available = false;
}

Texture::~Texture(){}
