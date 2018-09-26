using namespace std;

#ifndef LABEL_H
#define LABEL_H

#include <interface/InterfaceObject.h>
#include <font/Font.h>
#include <global/Color.h>
#include <global/Vector.h>

// Alignment modifiers:
#define ALIGN_LEFT		0
#define ALIGN_CENTER	1
#define ALIGN_RIGHT		2

class Label : public InterfaceObject {
	private:
		char*   text;
		Font*	font;
		Color*	color;
		
		Vector* label_size;
		double	text_size;

//		int		textwidth;
		int		alignment;

		// Used for alignment calc
  		void	calcTextWidth();		

	public:
		Label(double, double, double, double, Font*, int);
		virtual			~Label();


		void            setFont(Font* _font){ font = _font; }
		void			setText(const char*, ...);
		char*           getText(){ return text; }
		Vector*         getLabelSize(){ return label_size; }

		void			setTextSize(double);

		// Change color of font
		void            setColor(double, double, double, double);
		Color*			getColor(){	return color; }

		virtual void	paint();
};

#endif
