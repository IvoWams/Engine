#include <interface/MouseCursor.h>
#include <gl/gl.h>

MouseCursor::MouseCursor(double x, double y) :	InterfaceObject(x, y, 0, 0),
							 			 		MouseListener(){}

MouseCursor::~MouseCursor(){}

void	MouseCursor::setPosition(double _x, double _y){
	x = _x;
	y = _y;
}

void	MouseCursor::onMouseMove(double _x, double _y){
	x+= _x;
	y+= _y;
}

void	MouseCursor::onMouseDown(double btn){
	mousedown = true;
}

void	MouseCursor::onMouseUp(double btn){
	mousedown = false;
}

void	MouseCursor::vlak(double x, double y){
	glVertex2f(x, y);
	glVertex2f(x+15, y+15);
	glVertex2f(x, y+20);
}

void	MouseCursor::paint(){
	glLoadIdentity();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

	Color mousecolor;

	if(mousedown){
		mousecolor = Color(0.1,0.3,0.7);
	} else {
		mousecolor = Color(0.3,0.5,0.9);
 	}

	// Make it look like it has a shadow, with blending copies
	// Need to test on performance, doesnt seem to take much

	glColor4f(0,0,0,0.2);
	glBegin(GL_TRIANGLES);

	vlak(x-1, y-1);
	vlak(x,   y-1);
	vlak(x+1, y-1);

	vlak(x-1, y);
	vlak(x+1, y);
	vlak(x+2, y);

	vlak(x-1, y+1);
	vlak(x,   y+1);
	vlak(x+1, y+1);
	vlak(x+2, y+1);

	vlak(x,   y+2);
	vlak(x+1, y+2);
	vlak(x+2, y+2);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(mousecolor.R, mousecolor.G,mousecolor.B);
	glVertex2f(x, y);
	glColor3f(mousecolor.R, mousecolor.G*1.1,mousecolor.B*1.1);
	glVertex2f(x+15, y+15);
	glColor3f(mousecolor.R, mousecolor.G*1.5,mousecolor.B*1.7);
	glVertex2f(x, y+20);
	glEnd();

}
