#include <font/Font.h>
#include <global/Globals.h>
#include <iostream>
#include <fstream>
#include "gl/gl.h"

Font::Font(const string& _fname /*, int texture_size */, int _glyph_size){
	filename = _fname;
	glyph_size = _glyph_size;
	if(glyph_size<2)glyph_size=2;
	
	int texture_size = 64;	// smallest possible texture size

	char* buffer = (char*)malloc(255);
	bool  loop = true;
	
	int t = timeGetTime();
	available = false;
	
	while(loop){
		sprintf(buffer, "%s %d", filename.data(), glyph_size);
		string texturehandle = buffer;
    
	    texture = Globals::getGlobals()->engine->getTextureHandler()->getTexture(texturehandle);
    
		// Generate Glyph data from font
		int result = createFonts(texture_size, glyph_size, char(32), char(127));
		if(result == 0){
			available = true;
		    dlist = glGenLists(255);
	
			if(available)for(int i=0;i<255;++i)if(gdata[i].available){
				glNewList(dlist+i, GL_COMPILE);
				prePaint((char)i);
				glEndList();
			}
			
			loop = false;
			
		}else if(result == -4){
			// Target texture too small!
			if(texture_size<2048){
				texture_size += texture_size;	// 64->128->256->512->1024->2048->4096->8192->...?
			}else{
				loop = false;
			}
			
		}else{
			// failure
			loop = false;
		}
	}
	
	free(buffer);	
}

Font::~Font(){
	// We should prevent the destruction of the font object until all references are gone
	if(ref==0)glDeleteLists(dlist, 255);

	char* buffer = (char*)malloc(255);
	sprintf(buffer, "%s %d %d", filename.data(), texture->size, glyph_size);
	string texturehandle = buffer;
	free(buffer);
	
	// Texture handler handles the texture object itself
	Globals::getGlobals()->engine->getTextureHandler()->freeTexture(texturehandle);
}

// Creates a texture of texture_size in which the TrueFont lib is used to fill this
// texture up with the chosen font, using size and starting and finish character.
int		Font::createFonts(int texture_size, int glyph_size, char firstchar, char lastchar){
	// unset glyph data
	for(int i=0;i<255;++i)gdata[i].available=false;
	
	texture->size = texture_size;
	float	tunit = 1.0/texture_size;	// single pixel in the texture

	// Position in the target texture
	int tex_x = 0;
	int tex_y = 0;

	// Target texture
	GLubyte* texdata = new GLubyte[2*texture_size*texture_size];

	GLuint	tid = texture->glref;
	int	greatest_height = 0;

	// Initialize FreeType lib
	FT_Library library;
	if(FT_Init_FreeType(&library)!=0)return -1;
	FT_Face face;

	if(FT_New_Face(library, filename.data(), 0, &face)!=0){
		delete [] texdata;
		return -2;
	}
	
	FT_Set_Char_Size(face, glyph_size << 6, glyph_size << 6, 96, 96);	// 96 dpi

	// Generate glyph data for each character
	for(int c=firstchar;c<lastchar;++c){
		gdata[c].available = true;

		if(FT_Load_Glyph(face, FT_Get_Char_Index(face, c), 0)!=0){
			delete [] texdata;
			return -3;
		}
		
	    FT_Glyph glyph;
	    if(FT_Get_Glyph(face->glyph, &glyph)!=0){
			delete [] texdata;
			return -4;
		}
		
		FT_GlyphSlot gs = face->glyph;
		FT_Glyph_To_Bitmap(&glyph, ft_render_mode_normal, 0, 1);
	    FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
		FT_Bitmap& bitmap=bitmap_glyph->bitmap;

		// Remember highest character for a clear newline in the texture		
		if(bitmap.rows>greatest_height)greatest_height=bitmap.rows;
	
		// Temp storage space for glyph data
		GLubyte* expanded_data = new GLubyte[2*bitmap.width*bitmap.rows];
	
		// build glyph bitmap
		for(int j=0; j<bitmap.rows; j++)
			for(int i=0; i<bitmap.width; i++)
				expanded_data[2*(i+j*bitmap.width)]= expanded_data[2*(i+j*bitmap.width)+1] =
					(i>=bitmap.width || j>=bitmap.rows) ?
					0 : bitmap.buffer[i + bitmap.width*j];
	
		// cursoring texture, if x+width > texture_size, line feed
		if(tex_x+(2*bitmap.width)>2*texture_size){
			tex_x=0;
			tex_y+=1+greatest_height;
			greatest_height=0;
		}
	
		// Project glyph data into texture data
		for(int j=0; j<bitmap.rows;j++)
			for(int i=0; i<2*bitmap.width; i++)
				// If a pixel to be put into the bitmap is outside the texture size
				// throw an errer

				if(tex_x+i+2*(tex_y+j)*texture_size<2*texture_size*texture_size){
					texdata[tex_x+i+2*(tex_y+j)*texture_size]=expanded_data[i+2*j*bitmap.width];
				} else {
					delete [] texdata;
					delete [] expanded_data;
					return -4;
				}
		
		// Build GlyphData set for each character
		gdata[c].x1 = 0.5*tex_x*tunit;
		gdata[c].x2 = 0.5*tex_x*tunit+bitmap.width*tunit;
		gdata[c].y1 = tex_y * tunit;
		gdata[c].y2 = (tex_y+bitmap.rows) * tunit;
		gdata[c].advance = (gs->metrics.horiAdvance >> 6)*tunit;
		gdata[c].x_offset = (gs->metrics.horiBearingX >> 6)*tunit;
		gdata[c].y_offset = (gs->metrics.horiBearingY >> 6)*tunit;
		
		// cursor move
		tex_x += 2+(2*bitmap.width);
		
		delete [] expanded_data;
	}

	// Uninitialize library
	FT_Done_Face(face);
	FT_Done_FreeType(library);	

	// Create texture from texture data
    glBindTexture(GL_TEXTURE_2D, tid);   

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, texture_size, texture_size, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, texdata );

	delete [] texdata;

	return 0;
}

// Compileable instructions to paint a single character
void	Font::prePaint(char c){
	float tunit = 1.0/texture->size;					// single pixel in the texture
	float width = (gdata[c].x2 - gdata[c].x1)/tunit;	// x delta of a glyph
	float height = (gdata[c].y2 - gdata[c].y1)/tunit;	// y delta of a glyph
	float xoffset = (gdata[c].x_offset/tunit);			// horizontal bearing of a glyph
	float yoffset = (gdata[c].y_offset/tunit);			// vertical bearing of a glyph
	float advance = (gdata[c].advance/tunit);			// spacing until next char
	
	glBindTexture(GL_TEXTURE_2D, texture->glref);
	
	glBegin(GL_QUADS);
	glTexCoord2f(gdata[c].x1, gdata[c].y1);
	glVertex2f(xoffset, -yoffset);
	glTexCoord2f(gdata[c].x2, gdata[c].y1);
	glVertex2f(width + xoffset, -yoffset);
	glTexCoord2f(gdata[c].x2, gdata[c].y2);
	glVertex2f(width + xoffset, height - yoffset);
	glTexCoord2f(gdata[c].x1, gdata[c].y2);
	glVertex2f(xoffset, height - yoffset);
	glEnd();	
}

void	Font::paint(char c){
	glCallList(dlist+c);
}

double	Font::getWidth(char c){
	return (gdata[c].x2-gdata[c].x1)*texture->size;
}

double	Font::getHeight(char c){
	return (gdata[c].y2-gdata[c].y1)*texture->size;
}

double Font::getBearing(char c){
	return gdata[c].y_offset*texture->size;
}

double	Font::getAdvance(char c){
	return gdata[c].advance*texture->size;
}
