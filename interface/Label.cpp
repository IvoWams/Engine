#include <interface/Label.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <global/Globals.h>

Label::Label(double x, double y, double w, double h, Font* _font, int _alignment) : InterfaceObject(x, y, w, h){
	// Bug: new Font object needed for each Label
	font = _font;
	color = new Color(1,1,1,1);

	text = (char*)malloc(255);  // init 255 chars
	sprintf(text, "");          // clear chars

	alignment = _alignment;
	label_size = new Vector(0,0,0);
	text_size = 1.0;
}

Label::~Label(){
	delete label_size;
	free(text);
	delete color;
}

void	Label::calcTextWidth(){
	label_size->x = 0;
	label_size->y = 0;
	
	for(int i=0;i<strlen(text);++i){
		if(text_size*font->getHeight(text[i])>label_size->y)label_size->y = text_size*font->getHeight(text[i]);
		label_size->x += text_size*font->getAdvance(text[i]);
	}
}

void	Label::setText(const char* txt, ...){
	va_list argumentPtr;					// This will hold the pointer to the argument list
	va_start(argumentPtr, txt);				// Parse the arguments out of the string
	vsprintf(text, txt, argumentPtr);		// Now add the arguments into the full string
	va_end(argumentPtr);					// This resets and frees the pointer to the argument list.

	// Update textwidth
	calcTextWidth();
}

void    Label::setColor(double R, double G, double B, double A){
	color->R = R;
	color->G = G;
	color->B = B;
	color->A = A;
}

void	Label::setTextSize(double _size){
	text_size = _size;
}

void	Label::paint(){
	glLoadIdentity();

/*
	double x_offset = 0;
	if(strlen(text)>0)x_offset = 0.5 * font->getWidth(text[0]);
	double y_offset = 0.5 * height; // center of the label
*/	
	// Enable texture mapping etc...

	if(alignment==ALIGN_LEFT){
		glTranslatef(x, y, 0);		
	}else if(alignment==ALIGN_CENTER){
		glTranslatef(x+(width/2) - ((label_size->x)/2), y, 0);
	}else if(alignment==ALIGN_RIGHT){
		glTranslatef(x+width - (label_size->x), y, 0);
	}else{
		glTranslatef(x, y, 0);
	}
/*
	// Test; kader om tekst
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(label_size->x, 0);
	glVertex2f(label_size->x, label_size->y);
	glVertex2f(0, label_size->y);
	glEnd();
*/
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);

//  glScalef(scale->x, scale->y, scale->z);
//  glRotatef(rotation->z, 0, 0, 1);
	glScalef(text_size, text_size, 1);

	// Shadow cast

	for(int i=0;i<strlen(text);++i){
	    glTranslatef(2,2,0);
	    glColor4f(0,0,0,0.9*color->A);
		font->paint(text[i]);
		glTranslatef(-2,-2,0);
	    glColor4f(color->R, color->G, color->B, color->A);
		font->paint(text[i]);
		glTranslatef(font->getAdvance(text[i]), 0, 0);
	}

	

}

