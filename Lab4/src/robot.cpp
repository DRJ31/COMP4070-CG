#include "drawings.h"

static int shoulder = 0, elbow = 0, status = 0, rotate_x = 0, rotate_y = 0, spin = 0;
static double y_axis = 0.5;
const GLfloat GREEN[] = { 0.0, 1.0, 0.0 };

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 400, 400);
	glPushMatrix();
//	glRotatef(rotate_x, 1.0, 0.0, 0.0);
//	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	gluLookAt(cos(spin * M_PI / 360 * 2) * 0.5, y_axis, sin(spin * M_PI / 360 * 2) * 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// Draw head
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 1.5);
	//glRotatef(90.0, 0.0, 0.0, 1.0);
	sphere(1.0, GREEN);

	// Draw left wire
	glPushMatrix();
	glTranslatef(-0.5, 0.0, 1.0);
	glRotatef(135.0, 0.0, 1.0, 0.0);
	cylinder(0.05, 0.5, GREEN);
	glPopMatrix();

	// Draw left wire
	glPushMatrix();
	glTranslatef(0.5, 0.0, 1.0);
	glRotatef(-135.0, 0.0, 1.0, 0.0);
	cylinder(0.05, 0.5, GREEN);
	glPopMatrix();

	// Draw body
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.3);
	cylinder(1.0, 2.0, GREEN);
	glPopMatrix();
	
	//Draw right hand
	glPushMatrix();
	glTranslatef(1.5, 0.0, -0.4);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.9, GREEN);
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.9);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.9, GREEN);
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw left hand
	glPushMatrix();
	glTranslatef(-1.5, 0.0, -0.4);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.9, GREEN);
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.9);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.9, GREEN);
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw Left foot
	glPushMatrix();
	glTranslatef(-0.5, 0.0, -2.5);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.6, GREEN);
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.6);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.6, GREEN);
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw right foot
	glPushMatrix();
	glTranslatef(0.5, 0.0, -2.5);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.6, GREEN);
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.6);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.18, 0.6, GREEN);
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	glPopMatrix();
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
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(40.0, tick, 0);
//	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}
