#include "drawings.h"

void sphere(double radius, const GLfloat *color) {
	vector<float *> v;
	int rings = 20;
	int sectors = 20;
	float x, y, z, l;

	// Get points
	for (int i = 0; i < rings; i++) {
		for (int j = 0; j < sectors; j++) {
			l = cos(asin(1.0 * i / rings)) * radius;
			x = cos(j * M_PI * 2 / sectors) * l;
			y = sin(j * M_PI * 2 / sectors) * l;
			z = i * radius / rings;
			float *pos = new float[3];
			pos[0] = x;
			pos[1] = y;
			pos[2] = z;
			v.push_back(pos);
		}
	}

	// Draw sphere
	for (int i = 0; i < rings; i++) {
		glBegin(GL_LINE_LOOP);
		glColor3fv(color);
		for (int j = 0; j < sectors; j++) {
			glVertex3fv(v[sectors * i + j]);
		}
		glEnd();
	}

	for (int i = 0; i < sectors; i++) {
		glBegin(GL_LINE_STRIP);
		glColor3fv(color);
		glVertex3f(0, 0, radius);
		for (int j = rings - 1; j >= 0; j--) {
			glVertex3fv(v[sectors * j + i]);
		}
		glEnd();
	}

	for (int i = 0; i < sectors; i++) {
		glBegin(GL_LINES);
		glColor3fv(color);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3fv(v[i]);
		glEnd();
	}
}
