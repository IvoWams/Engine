using namespace std;

#ifndef CAMERA_H
#define CAMERA_H

#include <global/Vector.h>

class Camera {
	private:
		Vector* position;
		Vector* target;

	public:
		Camera();
		~Camera();

		Vector* getPosition();
		Vector* getTarget();
};

#endif
