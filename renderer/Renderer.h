#ifndef RENDERER_H
#define RENDERER_H

using namespace std;

#include <vector>
#include <global/RootObject.h>
#include <global/GlobalValues.h>
#include <gl/gl.h>
#include <gl/glu.h>

class Renderer {
	private:	
		int		left;
		int		top;
		int		width;
		int		height;
		int		bpp;
		bool	fullscreen;

	public:
		Renderer();
		~Renderer();

		void	changeResolution(int, int, int, int, int, bool);

		int		getLeft(){ return left; }
		int		getTop(){ return top; }
		int		getWidth(){ return width; }
		int 	getHeight(){ return height; }
		int		getBpp(){ return bpp; }
		bool	getFullscreen(){ return fullscreen; }

		// Set up 2D scene (for HUD/UI, etc...):
		void						setOrthoMode(int, int, int, int);   // partly
		void                        setOrthoMode();                     // full
		
		// Use the next method for preventing painting outside a given rectangle
		void                        setClipping(int, int, int, int);
		void                        setNoClipping();    // reset clipping window

		// Set up 3D scene (game objects...):
		void						setPerspectiveMode();

		// renderer pre paint functions
		void						start();

		// renderer post paint functions
		void						finish();

};

#endif
