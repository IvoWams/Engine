using namespace std;

#ifndef FONT_H
#define FONT_H

#include <string>
#include <texture/Texture.h>

#include <ft2build.h>
#include <freetype.h>
#include <ftglyph.h>
#include <ftoutln.h>
#include <fttrigon.h>

// Get next x^2 value from a
inline int next_p2(int a){
	int rval=1;
	while(rval<a) rval<<=1;
	return rval;
}

// Glyph data
typedef struct {
	bool	available;	// set if generated or not
	float	x1;			// lefftop corner in the texture
	float	y1;
	float	x2;			// rightbottom corner in the texture
	float	y2;
	float	advance;	// ruler displacement
	float	x_offset;	// bearing displacement
	float	y_offset;
} GlyphData;


class Font {
	private:
		// pointer to used texture object
		Texture*		texture;

		// OpenGL Display list
		GLuint			dlist;

		// Number of references to this font object
		int				ref;

		// Bit set when succesful loaded
        bool			available;


		// prePaint method for display list paint
        void			prePaint(char c);

		GlyphData 		gdata[255];	// Reserve glyphdata for 255 character

        int				createFonts(int, int, char, char);

	public:
		Font(const string&, /* int, */ int);
		~Font();

        string			filename;
		int				glyph_size;

		// Attached texture
		Texture*		getTexture(){ return texture; }

		// Referencing/handle
		void			incRef(){ ref++; }
		void			decRef(){ ref--; }
		bool			hasRef(){ return ref>0; }

        GlyphData*		getGlyphData(char c){ return &gdata[c]; }

		// Paint character at the current position using current rotation using display list
		void			paint(char c);

		// Get Pixel Info
		double			getWidth(char);
		double			getHeight(char);
		double			getBearing(char);
		double			getAdvance(char);

		bool			isAvailable(){ return available; }
};

#endif
