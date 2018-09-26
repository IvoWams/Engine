#include <interface/Button.h>
#include <gl/gl.h>

Button::Button(double x, double y, double w, double h, Font* font) : InterfaceObject(x, y, w, h){
//	label = new Label(x+w/2 - 4, y - 1, font, ALIGN_CENTER);
	label = new Label(x, y, w, h, font, ALIGN_CENTER);
	addObject(label);
}

Button::Button(Button* original) : InterfaceObject(original){
	// Not implemented yet
}

Button::~Button(){
	delObject(label);
	delete label;
}

void        Button::paint(){
	glLoadIdentity();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

	double bevel	= 1;
	if(pressed)bevel=0;

	Color pane = Color(0.1, 0.2, 0.3);
	if(mouseover)pane = Color(0.2, 0.3, 0.4);
	double blend = 0.6;
//	if(focus)blend = 0.9;

	Color highlight = Color(pane.R*1.2, pane.G*1.2, pane.B*1.2);
	Color shadow = Color(pane.R*0.8, pane.G*0.8, pane.B*0.8);
	Color finehilight = Color(pane.R*1.5, pane.G*1.5, pane.B*1.5);
	Color darkshadow = Color(pane.R*0.5, pane.G*0.5, pane.B*0.5);

	// Create a black border
	glBegin(GL_QUADS);

	glColor4f(0,0,0,blend);
	glVertex2f(x-1, y-1);
	glVertex2f(x+width+1, y-1);
	glVertex2f(x+width+1, y+height+1);
	glVertex2f(x-1, y+height+1);

	glEnd();

	glBegin(GL_QUADS);

	glColor4f(highlight.R, highlight.G, highlight.B, blend);
	glVertex2f(x, y);
	glColor4f(finehilight.R, finehilight.G, finehilight.B, blend);
	glVertex2f(x+bevel, y+bevel);
	glColor4f(highlight.R, highlight.G, highlight.B, blend);
	glVertex2f(x+width-bevel, y+bevel);
	glVertex2f(x+width, y);

	glVertex2f(x, y);
	glColor4f(finehilight.R, finehilight.G, finehilight.B, blend);
	glVertex2f(x+bevel, y+bevel);
	glColor4f(highlight.R, highlight.G, highlight.B, blend);
	glVertex2f(x+bevel, y+height-bevel);
	glVertex2f(x, y+height);

	glColor4f(shadow.R, shadow.G, shadow.B, blend);

	glVertex2f(x+width, y);
	glVertex2f(x+width-bevel, y+bevel);
	glVertex2f(x+width-bevel, y+height-bevel);
	glColor4f(darkshadow.R, darkshadow.G, darkshadow.B, blend);
	glVertex2f(x+width, y+height);

	glColor4f(shadow.R, shadow.G, shadow.B, blend);
	glVertex2f(x, y+height);
	glVertex2f(x+bevel, y+height-bevel);
	glVertex2f(x+width-bevel, y+height-bevel);
	glColor4f(darkshadow.R, darkshadow.G, darkshadow.B, blend);
	glVertex2f(x+width, y+height);

	glColor4f(pane.R, pane.G, pane.B, blend);

	glVertex2f(x+bevel, y+bevel);
	glVertex2f(x+width-bevel, y+bevel);
	glVertex2f(x+width-bevel, y+height-bevel);
	glVertex2f(x+bevel, y+height-bevel);

	glEnd();


	// paint children
	for(int i=0;i<children->size();++i)
		(*children)[i]->paint();

}
