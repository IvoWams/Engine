#include <global/Globals.h>
#include <interface/InputBox.h>
#include <gl/gl.h>

// This class is pretty old, needs to be lookes at

InputBox::InputBox(int	x,
				   int	y,
				   int	w,
				   int	h,
				   Font* _font,
				   int		_maxlength)	: InterfaceObject(x,y, w, h)
				   						, InputListener()
										, TimerListener(){

//	label		= new Label(x+1, y+h - font->getHeight('X') -1, w, h, font, ALIGN_LEFT);
//	label->setColor(0.8,0.8,0, 0.5);

	color = new Color(1,1,1,1);
	text = (char*)malloc(255);
	sprintf(text,"");
	
	font = _font;
	
	maxlength	= _maxlength;

	bool	caps = false;
	
	paintcursor = false;
	cursor		= 0;
	
	blinker = new Timer(500);
	Globals::getGlobals()->engine->getTimerHandler()->addTimer(blinker);
	Globals::getGlobals()->engine->getTimerHandler()->addListener(this);
}

InputBox::~InputBox(){
	Globals::getGlobals()->engine->getTimerHandler()->delListener(this);
	Globals::getGlobals()->engine->getTimerHandler()->delTimer(blinker);
	delete blinker;
}

void	InputBox::addChar(char c){

	if(strlen(text)<maxlength){

		// push characters right of the cursor one place to the right
		for(int i=strlen(text);i>=cursor;--i)
			text[i+1] = text[i];
		// insert character
		text[cursor] = c;
		cursor++;
	}

}

void	InputBox::onKeyDown(int code){
	if(!focus)return;                   // dont read keys when your not focused
	                                    // maybe possible to remove as listener when it is not focused

	paintcursor = true;
	
	// remove cursor character
	for(int i=cursor;i<strlen(text);++i)
		text[i]=text[i+1];
	if(code == 16)
		caps = true;
	if(code == 8 )						// Backspace
		if(cursor>0){
			for(int i=cursor-1;i<strlen(text);++i)
				text[i]=text[i+1];
			cursor--;
		}
	if(code == 32)
		addChar(' ');
	if(code>=65 && code<=90){
		if(!caps)code+=32;
		addChar(code);
	}
	if(code>=48 && code<=58)
		addChar(code);
	if(code==190)
		addChar('.');
	if(code==37)        // arrow left
		if(cursor>0)cursor--;
	if(code==39)        // arrow right
		if(cursor<strlen(text))cursor++;
	if(code==46)	// delete button
		for(int i=cursor;i<strlen(text);++i)
			text[i]=text[i+1];

//	Enable to detect scancodes vs keycodes
//	sprintf(line, "%d", code);
		
//	addChar(code);

	// Add cursor char

	for(int i=strlen(text);i>=cursor;--i)
		text[i+1] = text[i];
	// insert character
	text[cursor] = 31;
	
//	text->calcTextWidth();
}

void 	InputBox::onKeyUp(int code){
	if(code==16)
		caps = false;
}

void	InputBox::paint(){
	glLoadIdentity();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

	double bevel	= 1;
//	if(pressed)bevel=0;

	Color pane = Color(0.1, 0.2, 0.3);
	if(mouseover)pane = Color(0.2, 0.3, 0.4);
	double blend = 0.6;
	if(focus)blend = 0.7;

	// Note: reversed colors of button
	Color darkshadow = Color(pane.R*1.2, pane.G*1.2, pane.B*1.2);
	Color finehilight = Color(pane.R*0.8, pane.G*0.8, pane.B*0.8);
	Color shadow = Color(pane.R*1.5, pane.G*1.5, pane.B*1.5);
	Color highlight = Color(pane.R*0.5, pane.G*0.5, pane.B*0.5);

	
	// Create a black border
	/*
	glBegin(GL_QUADS);

	glColor4f(0,0,0,blend);
	glVertex2f(x-1, y-1);
	glVertex2f(x+width+1, y-1);
	glVertex2f(x+width+1, y+height+1);
	glVertex2f(x-1, y+height+1);
	glEnd();

	*/

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

	// Next code has pieces of label code

	// determine boundaries

	double clip_left = x + bevel;
	double clip_right = x+width - bevel - 1; // 1 is for the cursor size
	double clip_width = clip_right - clip_left;
	double clip_top = y + bevel;
	double clip_bottom = y+height - bevel;
	double clip_height = clip_bottom - clip_top;

	
	// Clip to inputbox
	Globals::getGlobals()->engine->getRenderer()->setClipping(clip_left, clip_top, clip_width + 1, clip_height);

	// Enable texture mapping etc...
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);
    
    // Calc text width and space between cursor and end of text
    int textwidth = 0;
    int cursorpost = 0;
    int cursorpre = 0;

    for(int i=0;i<strlen(text);++i){
        textwidth+=font->getWidth(text[i]);
        if(i>=cursor)
			cursorpost+=font->getWidth(text[i]);
		else
			cursorpre+=font->getWidth(text[i]);
	}   

	// Inputbox behavior:
	if(textwidth<clip_width)                    // If text width is smaller than box size
		glTranslatef(clip_left, clip_top, 0);   // just paint from left to right
	else
	    if(cursorpost > clip_width/2)
			if(cursorpre < clip_width/2)
			    glTranslatef(clip_left, clip_top, 0);
			else
		        glTranslatef(clip_left - (textwidth-clip_width) + (cursorpost - clip_width/2), clip_top, 0);   // move it in the center
		else
		    glTranslatef(clip_left - (textwidth-clip_width), clip_top, 0);


    glColor4f(color->R, color->G, color->B, color->A);

//  glScalef(scale->x, scale->y, scale->z);
//  glRotatef(rotation->z, 0, 0, 1);

	if(strlen(text)==0)if(paintcursor && focus){
		    glDisable(GL_TEXTURE_2D);
		    glEnable(GL_COLOR_MATERIAL);

			glColor4f(1,1,1,1);
			glBegin(GL_QUADS);
			glVertex2f(0,2);
			glVertex2f(1,2);
			glVertex2f(1,height-2); // cursor size is determined by font size, not inputbox size?
			glVertex2f(0,height-2);
			glEnd();

		    glEnable(GL_TEXTURE_2D);
		    glDisable(GL_COLOR_MATERIAL);
		}

	for(int i=0;i<strlen(text);++i){
		font->paint(text[i]);
		glTranslatef(font->getWidth(text[i]), 0, 0);
		if(i==cursor && paintcursor && focus){
		    glDisable(GL_TEXTURE_2D);
		    glEnable(GL_COLOR_MATERIAL);

			glColor4f(1,1,1,1);
			glBegin(GL_QUADS);
			glVertex2f(0,2);
			glVertex2f(1,2);
			glVertex2f(1,height-2); // cursor size is determined by font size, not inputbox size?
			glVertex2f(0,height-2);
			glEnd();

		    glEnable(GL_TEXTURE_2D);
		    glDisable(GL_COLOR_MATERIAL);
		}
	}

	// Reset clipping
	Globals::getGlobals()->engine->getRenderer()->setNoClipping();
}

char*	InputBox::getValue(){
	return text;
}

void    InputBox::onTime(Timer* t){
	if(t==blinker)paintcursor=!paintcursor;
}
