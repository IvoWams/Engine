#include <global/Vector.h>
#include <global/GlobalValues.h>
#include <gl/gl.h>
#include <string>

using namespace std;

#ifndef TOOLS_H
#define TOOLS_H

// Math func

double		getAngle(const Vector&, const Vector&);
void		crossVector(Vector&, const Vector&, const Vector&);
void		divVector(Vector&, const Vector&, const Vector&);
double		lengthVector(const Vector&);
void		normalizeVector(Vector&);
void		getNormal(Vector&, const Vector&, const Vector&, const Vector&);

void		paintRect(const Vector&, const Vector&, const Vector&, const Vector&);
void		paintTria(const Vector&, const Vector&, const Vector&);

#endif
