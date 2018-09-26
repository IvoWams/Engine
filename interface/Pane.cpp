#include <interface/Pane.h>
#include <gl/gl.h>

Pane::Pane(double x, double y, double w, double h) : InterfaceObject(x, y, w, h){
	show	= true;
	enabled = false;
}

Pane::~Pane(){}

void	Pane::vlak(double x, double y, double w, double h){
	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y+height);
	glVertex2f(x, y+height);
}

void	Pane::paint(){
	glLoadIdentity();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

	double	bevel	= 2;

	Color pane = Color(0.1, 0.2, 0.3);
//	if(mouseover)pane = Color(0.2, 0.3, 0.4);
	double blend = 0.6;
//	if(focus)blend = 0.9;

	Color highlight = Color(pane.R*1.2, pane.G*1.2, pane.B*1.2);
	Color shadow = Color(pane.R*0.8, pane.G*0.8, pane.B*0.8);
	Color finehilight = Color(pane.R*1.5, pane.G*1.5, pane.B*1.5);
	Color darkshadow = Color(pane.R*0.5, pane.G*0.5, pane.B*0.5);

	glBegin(GL_QUADS);

	glColor4f(0,0,0,0.2);

	vlak(x-1, y-1, width, height);
	vlak(x,   y-1, width, height);
	vlak(x+1, y-1, width, height);

	vlak(x-1, y,   width, height);
	vlak(x+1, y,   width, height);
	vlak(x+2, y, width, height);

	vlak(x-1, y+1,   width, height);
	vlak(x,   y+1, width, height);
	vlak(x+1, y+1, width, height);
	vlak(x+2, y+1, width, height);

	vlak(x,   y+2, width, height);
	vlak(x+1, y+2, width, height);
	vlak(x+2, y+2, width, height);

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
