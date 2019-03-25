#ifndef CG_DRAWINGS_H
#define CG_DRAWINGS_H
#define _USE_MATH_DEFINES
#include <cmath>
#include <GL/glut.h>
#include <vector>
#include <cstdio>

using namespace std;

void sphere(double radius, const GLfloat *color);

void cylinder(double radius, double height, const GLfloat *color);

#endif //CG_DRAWINGS_H
