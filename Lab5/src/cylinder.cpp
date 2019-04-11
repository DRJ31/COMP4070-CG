#include "drawings.h"

const GLfloat GREEN[] = { 0.0, 1.0, 0.0 };

void cylinder(double radius, double height, const GLfloat *color)
{

	float const R = 1. / (float)(RINGS - 1);
	float const S = 1. / (float)(SECTORS - 1);
	//float radius = 0.3;
	//float HEIGHT = 0.5;
	//int rings = 10;
	//int sectors = 10; 
	float v[RINGS*SECTORS][3];
	int s, r, t = 0;

	// ---------------- the side face -------------------------------------
	for (r = 0; r < RINGS; r++) {
		for (s = 0; s < SECTORS; s++) {

			//draw according to the coordinate of the ppt
			//float const z = cos(M_PI * r * R);
			//float const x = sin(M_PI * r * R) * cos(2 * M_PI * s * S);
			//float const y = sin(M_PI * r * R) * sin(2 * M_PI * s * S);

			//draw accordign to the coordinate of OpenGL
			//float const y = cos(M_PI * r * R);
			//float const z = sin(M_PI * r * R) * cos(2 * M_PI * s * S);
			//float const x = sin(M_PI * r * R) * sin(2 * M_PI * s * S);

			float const y = r * R;
			float const z = cos(2 * M_PI * s * S);
			float const x = sin(2 * M_PI * s * S);

			v[t][0] = x * radius;
			v[t][1] = y * height;
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

	// ---------------- the lower face -------------------------------------
	t = 0;
	for (r = 0; r < 2; r++) {
		for (s = 0; s < SECTORS; s++) {

			float const y = 0.0;   //all y coordinate is 0.0
			float z, x;
			if (r == 0)  // (0,0,0) will be the points on the first ring
			{
				z = 0.0;
				x = 0.0;
			}
			else
			{
				z = cos(2 * M_PI * s * S);
				x = sin(2 * M_PI * s * S);

			}
			v[t][0] = x * radius;
			v[t][1] = y * height;
			v[t][2] = z * radius;

			t++;

		}
	}

	t = 0;
	int idx_low[4 * 2 * SECTORS];

	for (r = 0; r < 2 - 1; r++) {
		for (s = 0; s < SECTORS; s++) {
			idx_low[4 * t + 0] = r * SECTORS + s;
			idx_low[4 * t + 1] = r * SECTORS + (s + 1);
			idx_low[4 * t + 2] = (r + 1) * SECTORS + (s + 1);
			idx_low[4 * t + 3] = (r + 1) * SECTORS + s;
			t++;
		}
	}


	for (int i = 0; i < SECTORS*(2 - 1) - 1; i++)
	{
		glBegin(GL_POLYGON);
		glColor3fv(GREEN);
		glNormal3f(v[index[4 * i + 0]][0], v[index[4 * i + 0]][1], v[index[4 * i + 0]][2]);
		
		glVertex3fv(v[idx_low[4 * i + 0]]);
		glNormal3f(v[index[4 * i + 1]][0], v[index[4 * i + 1]][1], v[index[4 * i + 1]][2]);
		
		glVertex3fv(v[idx_low[4 * i + 1]]);
		glNormal3f(v[index[4 * i + 2]][0], v[index[4 * i + 2]][1], v[index[4 * i + 2]][2]);
		
		glVertex3fv(v[idx_low[4 * i + 2]]);
		glNormal3f(v[index[4 * i + 3]][0], v[index[4 * i + 3]][1], v[index[4 * i + 3]][2]);
		
		glVertex3fv(v[idx_low[4 * i + 3]]);
		glEnd();
	}


	// ---------------- the upper face -------------------------------------
	t = 0;
	for (r = 0; r < 2; r++) {
		for (s = 0; s < SECTORS; s++) {

			float const y = 1.0;  // all y coordinate is 1.0
			float z, x;
			if (r == 0) // (0,0,0) will be the points on the first ring
			{
				z = 0.0;
				x = 0.0;
			}
			else
			{
				z = cos(2 * M_PI * s * S);
				x = sin(2 * M_PI * s * S);

			}
			v[t][0] = x * radius;
			v[t][1] = y * height;
			v[t][2] = z * radius;

			t++;

		}
	}

	t = 0;


	for (r = 0; r < 2 - 1; r++) {
		for (s = 0; s < SECTORS; s++) {
			idx_low[4 * t + 0] = r * SECTORS + s;
			idx_low[4 * t + 1] = r * SECTORS + (s + 1);
			idx_low[4 * t + 2] = (r + 1) * SECTORS + (s + 1);
			idx_low[4 * t + 3] = (r + 1) * SECTORS + s;
			t++;
		}
	}


	for (int i = 0; i < SECTORS*(2 - 1) - 1; i++)
	{
		glBegin(GL_POLYGON);
		glColor3fv(GREEN);
		glVertex3fv(v[idx_low[4 * i + 0]]);
		glVertex3fv(v[idx_low[4 * i + 1]]);
		glVertex3fv(v[idx_low[4 * i + 2]]);
		glVertex3fv(v[idx_low[4 * i + 3]]);
		glEnd();
	}
}
