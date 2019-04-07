#include "drawings.h"

static int shoulder = 0, elbow = 0, status = 0, rotate_x = 0, rotate_y = 0, spin = 0;
static double y_axis = 0.5;
const GLfloat GREEN[] = { 0.0, 1.0, 0.0 };

void robot() {
	glPushMatrix();
	// glRotatef(rotate_x, 1.0, 0.0, 0.0);
	// glRotatef(rotate_y, 0.0, 1.0, 0.0);
	
	// Draw head
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.27);
	sphere(0.3, GREEN); // HEAD

	// Draw left wire
	glPushMatrix();
	glTranslatef(-0.15, 0.0, 0.36);
	glRotatef(135.0, 0.0, 1.0, 0.0);
	cylinder(0.015, 0.15, GREEN); // Left wire
	glPopMatrix();

	// Draw right wire
	glPushMatrix();
	glTranslatef(0.15, 0.0, 0.3);
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	cylinder(0.015, 0.15, GREEN); // Right wire
	glPopMatrix();

	// Draw body
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.09);
	cylinder(0.3, 0.6, GREEN); // Body
	glPopMatrix();
	
	//Draw right hand
	glPushMatrix();
	glTranslatef(0.45, 0.0, -0.12);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.27, GREEN); // Right shoulder
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.27);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.27, GREEN); // Right elbow
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw left hand
	glPushMatrix();
	glTranslatef(-0.45, 0.0, -0.12);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.27, GREEN); // Left shoulder
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.27);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.27, GREEN); // Left elbow
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw Left foot
	glPushMatrix();
	glTranslatef(-0.15, 0.0, -0.75);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.18, GREEN); // Left foot
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.18);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.18, GREEN); // Left foot
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw right foot
	glPushMatrix();
	glTranslatef(0.15, 0.0, -0.75);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.18, GREEN); // Right foot
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.18);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.054, 0.18, GREEN); // Right foot
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// gluPerspective(100.0, (GLfloat)500 / (GLfloat)500, 0.0, 20.0);
	glFrustum(-1, 1, -1, 1, 0, 20);
	// glOrtho(-1, 1, -1, 1, 0, 20);
	glViewport(100, 50, 400, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cos(spin * M_PI / 360 * 2) * 0.5, y_axis, sin(spin * M_PI / 360 * 2) * 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	robot();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void specialKeys(int key, int x, int y) {
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	// Request display update
	glutPostRedisplay();
}

void tick(int value) {
	switch (status)
	{
	case 0:
		shoulder += 4;
		elbow += 4;
		if (shoulder >= 40) {
			status++;
		}
		break;
	case 1:
		shoulder -= 4;
		elbow -= 4;
		if (shoulder <= -40) {
			status--;
		}
		break;
	default:
		break;
	}
	spin += 10;
	if (spin > 360)
		spin %= 360;
	if (y_axis > -0.5)
		y_axis -= 0.01;
	else
		y_axis = 0.5;
	glutTimerFunc(40.0, tick, 0);
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(40.0, tick, 0);
//	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}
