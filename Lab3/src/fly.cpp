#define _USE_MATH_DEFINES

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <cmath>
#include <iostream>
#include <random>

namespace GlobalData {
    double radius = 0.5;
    double spin = 0.0;//rotate angle
    int status = 0;
    int count = 0; // Count the time of iteration
    double move_y = radius;
    double r = 0; // Current value of radius
}

using namespace std;
using namespace GlobalData;


void koch_snowflake(double x, double y, double angle, double length, int n) {
    if (n == 0) {
        double x1 = x + length * cos(angle);
        double y1 = y + length * sin(angle);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x1, y1);
        glEnd();
    }
    else {
        length /= 3;
        n--;
        koch_snowflake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle -= M_PI / 3;
        koch_snowflake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle += M_PI * 2 / 3;
        koch_snowflake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle -= M_PI / 3;
        koch_snowflake(x, y, angle, length, n);

    }
}


vector< vector<double> > get_points(double x, double y, double length, double angle) {
    vector< vector<double> > points(3);
    points[0].push_back(x);
    points[0].push_back(y);
    points[1].push_back(x + length * cos(angle));
    points[1].push_back(y + length * sin(angle));
    points[2].push_back(x + length * cos(angle + M_PI / 3));
    points[2].push_back(y + length * sin(angle + M_PI / 3));
    return points;
}


void snowflake(double half_length, double init_y) {
    int iters = 5;
    double angle = 0;
    vector< vector<double> > points = get_points(-half_length, -half_length * sqrt(3) / 3 + init_y, half_length * 2, angle);

    koch_snowflake(points[0][0], points[0][1], angle, half_length * 2, iters);
    koch_snowflake(points[1][0], points[1][1], angle + M_PI * 2 / 3, half_length * 2, iters);
    koch_snowflake(points[2][0], points[2][1], angle - M_PI * 2 / 3, half_length * 2, iters);
}


void tick(int value)
{
    if (status > 3)
        status = 0;
    switch (status) {
        case 0: // Move from center to circle side
            if (GlobalData::count > 5) {
                status++;
                GlobalData::count = 0;
                break;
            }
            r = radius / 6 * GlobalData::count;
            GlobalData::count++;
            break;
        case 1:// Spin in circle
            if (GlobalData::count > 5) {
                status++;
                break;
            }
            spin = spin + 10.0;
            if (spin > 360.0) {
                spin = spin - 360.0;
                GlobalData::count++;
            }
            move_y -= radius / 3 / 36;
            break;
        case 2: // Move from circle side to center
            if (GlobalData::count < 0) {
                GlobalData::count = 0;
                status++;
                break;
            }
            r = radius / 6 * GlobalData::count;
            GlobalData::count--;
            break;
        case 3: // Move from bottom to top
            if (GlobalData::count > 5) {
                GlobalData::count = 0;
                status = 0;
                break;
            }
            move_y += radius / 3;
            GlobalData::count++;
            break;
    }
    //recall timer, you can change the time (60.0f) to slow or increase the speed.
    glutTimerFunc(40.0, tick, 0);
    glutPostRedisplay();
}


void display()
{
    default_random_engine engine;
    engine.seed((unsigned long)(move_y * 100));
    uniform_real_distribution<double> u(0, 5);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //rotate around z-axis
    glRotatef(spin, 0.0, radius, 0.0);
    glTranslatef(r * sin(M_PI / 4), 0.0, r * sin(M_PI / 4));
    snowflake(0.4, move_y);
    glRotatef(spin, 0.0, u(engine), 0.0);
    glTranslatef(r * sin(M_PI / 4), 0.0, r * sin(M_PI / 4));
    snowflake(0.2, move_y * 2);

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Flying Snowflake");
    glutDisplayFunc(display);
    glutTimerFunc(60.0, tick, 0);
    glutMainLoop();
    return 0;
}
