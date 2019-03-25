#include "drawings.h"
#include <iostream>

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


vector< vector<float> > get_points(float x, float y, float length, float angle) {
    vector< vector<float> > points(3);
    points[0].push_back(x);
    points[0].push_back(y);
    points[1].push_back(x + length * cos(angle));
    points[1].push_back(y + length * sin(angle));
    points[2].push_back(x + length * cos(angle + M_PI / 3));
    points[2].push_back(y + length * sin(angle + M_PI / 3));
    return points;
}


void draw() {
    int iters = 5;
    float half_length = 0.8;
    float angle = -M_PI / 6;
    vector< vector<float> > points = get_points(-half_length * sqrt(3) / 3 * 2, 0.0, half_length * 2, angle);

    koch_snowfake(points[0][0], points[0][1], angle, half_length * 2, iters);
    koch_snowfake(points[1][0], points[1][1], angle + M_PI * 2 / 3, half_length * 2, iters);
    koch_snowfake(points[2][0], points[2][1], angle -M_PI * 2 / 3, half_length * 2, iters);
}
