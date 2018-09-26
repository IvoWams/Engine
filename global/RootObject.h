using namespace std;

#ifndef ROOTOBJECT_H
#define ROOTOBJECT_H

#include <global/Vector.h>
#include <global/Color.h>

class RootObject {
	private:

	protected:
		Vector*	position;
		Vector*	rotation;
		Vector*	scale;
		Color*	color;
	
	public:
		RootObject();
//		RootObject(RootObject*);
		virtual ~RootObject();

		bool		flat;		// set true for ortho painting, else 3d painting (ordering of the mainengine loop)
		int			order;		// sorting order when adding to engine
		
		bool		visible;
		bool		enabled;
		
//        double      occlusion;  // blend value
        

		void		setPosition(const Vector&);
		void		setPosition(double, double, double);
		Vector* 	getPosition(){ return position; }
		
		void		setRotation(const Vector&);
		void		setRotation(double, double, double);
		Vector*		getRotation(){ return rotation; }
		
		void		setScale(const Vector&);
		void		setScale(double, double, double);
		Vector*		getScale(){ return scale; }

		void		setColor(const Color&);
		void		setColor(double, double, double, double);
		Color*		getColor(){ return color; }

		void		incPosition(double, double, double);
		void		incRotation(double, double, double);
		void		incScale(double, double, double);
		void		incColor(double, double, double, double);
	
		virtual void  paint();
};

#endif
