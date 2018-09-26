#include <global/Color.h>

Color::Color(){
	R = 0;
	G = 0;
	B = 0;
	A = 1.0;
}

Color::Color(double _R, double _G, double _B){
	R = _R;
	G = _G;
	B = _B;
	A = 1.0;
}

Color::Color(double _R, double _G, double _B, double _A){
	R = _R;
	G = _G;
	B = _B;
	A = _A;
}

Color::~Color(){}

void    Color::setColor(double _R, double _G, double _B){
	R = _R;
	G = _G;
	B = _B;
}

void	Color::setColor(double _R, double _G, double _B, double _A){
	R = _R;
	G = _G;
	B = _B;
	A = _A;
}

void    Color::incColor(double _R, double _G, double _B){
	R+=_R;
	G+=_G;
	B+=_B;
}

void	Color::incColor(double _R, double _G, double _B, double _A){
    R+=_R;
    G+=_G;
    B+=_B;
    A+=_A;
}
