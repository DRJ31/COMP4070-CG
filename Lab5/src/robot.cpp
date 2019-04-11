#include "drawings.h"

const GLfloat GREEN[] = { 0.0, 1.0, 0.0 };


static int shoulder = 0, elbow = 0, angle0 = 0, angle1 = 0, rotate_x = 0, rotate_y = 0;
static GLfloat mat_specular[] = { 1.0,1.0,1.0,1.0 };
static GLfloat mat_shininess[] = { 50.0 };
static GLfloat exponent[] = { 0.0 };
static GLfloat light_position0[] = { 1.0,1.0,1.0,0.0 };
static GLfloat light_position1[] = { 1.0,1.0,1.0,1.0 };
static GLfloat spot_direction[] = {-1.0, 0.0, 0.0};
static GLfloat red_light[] = { 1.0,0.0,0.0,1.0 };
static GLfloat blue_light[] = {0.0, 0.0, 1.0, 1.0};
static GLfloat lmodel_ambient[] = { 0.1,0.1,0.1,1.0 };
static GLint flat_smooth = GL_SMOOTH;

void robot() {
	glPushMatrix();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	
	// Draw head
	glPushMatrix();
	glTranslatef(0.0, 0.8, 0.0);
	sphere(0.2, GREEN); // HEAD
	glPopMatrix();

	// Draw body
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	cylinder(0.3, 0.8, GREEN); // Body
	glPopMatrix();
	
	//Draw right hand
	glPushMatrix();
	glTranslatef(0.4, 0.2, 0.0);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.05, 0.4, GREEN); // Right shoulder
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.05, 0.4, GREEN); // Right elbow
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw left hand
	glPushMatrix();
	glTranslatef(-0.4, 0.2, 0.00);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.05, 0.4, GREEN); // Left shoulder
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.05, 0.4, GREEN); // Left elbow
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw Left foot
	glPushMatrix();
	glTranslatef(-0.2, -0.6, 0.0);
	glRotatef(-(GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.07, 0.35, GREEN); // Left foot
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, -0.35, 0.0);
	glRotatef(-(GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.07, 0.35, GREEN); // Left foot
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	// Draw right foot
	glPushMatrix();
	glTranslatef(0.2, -0.6, 0.0);
	glRotatef((GLfloat)shoulder, 1.0, 0.0, 0.0);
	cylinder(0.07, 0.35, GREEN); // Right foot
	// Elbow start
	glPushMatrix();
	glTranslatef(0.0, -0.35, 0.0);
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	cylinder(0.07, 0.35, GREEN); // Right foot
	glPopMatrix();
	// Elbow end
	glPopMatrix();

	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(flat_smooth);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blue_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, red_light);
	glLightfv(GL_LIGHT1, GL_AMBIENT, red_light);
	glLightfv(GL_LIGHT1, GL_SPECULAR, red_light);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 15.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);


	glLoadIdentity();

	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	robot();
	// cylinder(0.3, 0.6, GREEN);
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'f':
		flat_smooth = GL_FLAT;
		glutPostRedisplay();
		break;
	case 's':
		flat_smooth = GL_SMOOTH;
		glutPostRedisplay();
		break;
	case '1':
		glEnable(GL_LIGHT0);
		// glEnable(GL_LIGHT1);
		break;
	case '0':
		glDisable(GL_LIGHT0);
		// glDisable(GL_LIGHT1);
		break;
	default:
		break;
	}
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
	if (angle0 == 7200) {
		light_position0[0] = 1;
		light_position0[1] = 1;
		light_position0[2] = 1;
		angle0 = 0;
	}
	if (angle1 == 7200) {
		light_position1[0] = 1;
		light_position1[1] = 1;
		light_position1[2] = 1;
		angle1 = 0;
	}
	if (angle1 % 360 == 0)
		light_position1[1] -= 0.1;
	if (angle0 % 360 == 0) 
		light_position0[1] -= 0.1;
	light_position0[0] = sqrt(2) * cos(angle0 * M_PI / 360 + M_PI / 4);
	light_position1[0] = sqrt(2) * cos(angle1 * M_PI / 360 + M_PI / 4);
	light_position0[2] = sqrt(2) * sin(angle0 * M_PI / 360 + M_PI / 4);
	light_position1[2] = sqrt(2) * sin(angle1 * M_PI / 360 + M_PI / 4);
	printf("(%f %f %f) (%f %f %f)\n", light_position0[0], light_position0[1], light_position0[2], light_position1[0], light_position1[1], light_position1[2]);
	angle0++;
	angle1 += 2;
	glutTimerFunc(1.0, tick, 0);
	glutPostRedisplay();
}

void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glEnable(GL_DEPTH_TEST);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(40.0, tick, 0);
	glutSpecialFunc(specialKeys);
	glutMainLoop();
	return 0;
}
