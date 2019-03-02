#include "drawings.h"

using namespace std;


void cylinder() {
    vector<float *> v;
    float radius = 0.3;
    float height = 1.2;
    int rings = 25;
    int sectors = 35;
    float x, y, z;

    // Get all the points
    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < sectors; j++) {
            x = cos(j * M_PI * 2 / sectors) * radius;
            y = sin(j * M_PI * 2 / sectors) * radius;
            z = i * height / rings - height / 2;
            float *pos = new float[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
            v.push_back(pos);
        }
    }

    // Draw rings
    for (int i = 0; i < rings; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(0.0, 1.0, 1.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(v[sectors * i + j]);
        }
        glEnd();
    }

    // Draw sectors
    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 1.0);
        for (int j = 0; j < rings; j++) {
            glVertex3fv(v[sectors * j + i]);
        }
        glEnd();
    }

    // Draw cap for bottom
    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(0.0, 0.0, -height / 2);
        glVertex3fv(v[i]);
        glEnd();
    }

    // Draw cap for top
    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(0.0, 0.0, height / 2 - height / rings);
        glVertex3fv(v[(rings - 1) * sectors + i]);
        glEnd();
    }
}
