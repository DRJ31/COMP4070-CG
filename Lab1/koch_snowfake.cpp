#include "drawings.h"

using namespace std;


void create_window() {
    glutCreateWindow("Koch Snowfake");
}


void koch_snowfake(float x, float y, double angle, float length, int n) {
    if (n == 0) {
        float x1 = x + length * cos(angle);
        float y1 = y + length * sin(angle);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x1, y1);
        glEnd();
    }
    else {
        length /= 3;
        n--;
        koch_snowfake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle -= M_PI / 3;
        koch_snowfake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle += M_PI * 2 / 3;
        koch_snowfake(x, y, angle, length, n);

        x += length * cos(angle);
        y += length * sin(angle);
        angle -= M_PI / 3;
        koch_snowfake(x, y, angle, length, n);

    }
}


void draw() {
    int iters = 5;
    float half_length = 0.8;

    koch_snowfake(-half_length, half_length * (-sqrt(3)) / 3, 0.0, half_length * 2, iters);
    koch_snowfake(half_length, half_length * (-sqrt(3)) / 3, M_PI * 2 / 3, half_length * 2, iters);
    koch_snowfake(0, half_length * sqrt(3) / 3 * 2, -M_PI * 2 / 3, half_length * 2, iters);
}
