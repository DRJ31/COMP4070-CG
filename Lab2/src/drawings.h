#ifndef CG_DRAWINGS_H
#define CG_DRAWINGS_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

void draw();

void create_window();

#endif //CG_DRAWINGS_H
