#ifndef CG_DRAWINGS_H
#define CG_DRAWINGS_H
#define _USE_MATH_DEFINES
#define RINGS 20
#define SECTORS 20

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

void sphere(double radius, const GLfloat *color);

void cylinder(double radius, double height, const GLfloat *color);

#endif //CG_DRAWINGS_H
