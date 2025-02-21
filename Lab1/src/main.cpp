#include "drawings.h"

using namespace std;


GLfloat rotate_y = 0;
GLfloat rotate_x = 0;


void display() {
    // Clear screen and buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // Main function of drawings
    draw();

    glFlush();
    glutSwapBuffers();
}


// specialKeys() Callback Function
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


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w > h) {
        float aspect = (float)w / (float)h;
        // glOrtho(-aspect, aspect, -1.0, 1.0, -10, 10);
        gluOrtho2D(-aspect, aspect, -1.0, 1.0); 
    }
    else {
        float aspect = (float)h / (float)w;
        // glOrtho(1.0, 1.0, -aspect, aspect, -10, 10);
        gluOrtho2D(-1.0, 1.0, -aspect, aspect);
    }
}


int main(int argc, char *argv[]) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    create_window();

    // Enable Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Callback Functions
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);

    // Pass control to GLUT for events
    glutMainLoop();

    return 0;
}
