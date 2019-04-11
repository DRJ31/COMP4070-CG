#include "drawings.h"

const GLfloat GREEN[] = { 0.0, 1.0, 0.0 };

void sphere(double radius, const GLfloat *color)
{
	float const R = 1. / (float)(RINGS - 1);
	float const S = 1. / (float)(SECTORS - 1);
	int s, r, t = 0;
	float v[RINGS*SECTORS][3];

	for (r = 0; r < RINGS; r++) {
		for (s = 0; s < SECTORS; s++) {
			//draw according to the coordinate of the ppt
			//float const z = cos(M_PI * r * R);
			//float const x = sin(M_PI * r * R) * cos(2 * M_PI * s * S);
			//float const y = sin(M_PI * r * R) * sin(2 * M_PI * s * S);

			//draw accordign to the coordinate of OpenGL
			float const y = cos(M_PI * r * R);
			float const z = sin(M_PI * r * R) * cos(2 * M_PI * s * S);
			float const x = sin(M_PI * r * R) * sin(2 * M_PI * s * S);

			v[t][0] = x * radius;
			v[t][1] = y * radius;
			v[t][2] = z * radius;

			t++;

		}
	}

	t = 0;
	int index[4 * RINGS*SECTORS];

	for (r = 0; r < RINGS - 1; r++) {
		for (s = 0; s < SECTORS; s++) {
			index[4 * t + 0] = r * SECTORS + s;
			index[4 * t + 1] = r * SECTORS + (s + 1);
			index[4 * t + 2] = (r + 1) * SECTORS + (s + 1);
			index[4 * t + 3] = (r + 1) * SECTORS + s;
			t++;
		}
	}

	for (int i = 0; i < SECTORS*(RINGS - 1) - 1; i++)
	{
		/*float p1[3] = { v[index[4 * i + 0]][0], v[index[4 * i + 0]][1],v[index[4 * i + 0]][2] };
		float p2[3] = { v[index[4 * i + 1]][0], v[index[4 * i + 1]][1],v[index[4 * i + 1]][2] };
		float p3[3] = { v[index[4 * i + 2]][0], v[index[4 * i + 2]][1],v[index[4 * i + 2]][2] };
		float v1[3] = { p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2] };
		float v2[3] = { p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2] };
		float norm[3] = { v[index[4 * i + 0]][0], v[index[4 * i + 0]][1],v[index[4 * i + 0]][2] };*/

		glBegin(GL_POLYGON);
		glColor3fv(GREEN);
		glNormal3f(v[index[4 * i + 0]][0], v[index[4 * i + 0]][1], v[index[4 * i + 0]][2]);
		glVertex3fv(v[index[4 * i + 0]]);
		glNormal3f(v[index[4 * i + 1]][0], v[index[4 * i + 1]][1], v[index[4 * i + 1]][2]);
		glVertex3fv(v[index[4 * i + 1]]);
		glNormal3f(v[index[4 * i + 2]][0], v[index[4 * i + 2]][1], v[index[4 * i + 2]][2]);
		glVertex3fv(v[index[4 * i + 2]]);
		glNormal3f(v[index[4 * i + 3]][0], v[index[4 * i + 3]][1], v[index[4 * i + 3]][2]);
		glVertex3fv(v[index[4 * i + 3]]);
		glEnd();
	}



}
