using namespace std;

#ifndef COLOR_H
#define COLOR_H

class Color {
	private:
	public:
		Color();
		Color(double, double, double);
		Color(double, double, double, double);
		~Color();

		double R, G, B, A;
		
		void  setColor(double, double, double);
		void  setColor(double, double, double, double);
		void  incColor(double, double, double);
		void  incColor(double, double, double, double);
};

#endif
