#include "drawings.h"

using namespace std;


void double_cone() {
    vector<float*> v;
    float radius = 0.6;
    float height = 0.6;
    int rings = 30;
    int sectors = 30;
    float x, y, z, l;

    // Get points
    for (int i = 0; i < rings - 1; i++) {
        for (int j = 0; j < sectors; j++) {
            l = radius - i * radius / rings;
            z = height - i * height / rings;
            x = cos(j * M_PI * 2 / sectors) * l;
            y = sin(j * M_PI * 2 / sectors) * l;
            float *pos = new float[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
            v.push_back(pos);
        }
    }

    for (int i = 0; i < rings - 1; i++) {
        for (int j = 0; j < sectors; j++) {
            l = radius - i * radius / rings;
            z = - height + i * height / rings;
            x = cos(j * M_PI * 2 / sectors) * l;
            y = sin(j * M_PI * 2 / sectors) * l;
            float *pos = new float[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
            v.push_back(pos);
        }
    }

    // Draw rings
    for (int i = 0; i < rings - 1; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(0.0, 1.0, 0.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(v[i * sectors + j]);
        }
        glEnd();
    }

    for (int i = rings - 1; i < 2 * rings - 3; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(0.0, 1.0, 0.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(v[i * sectors + j]);
        }
        glEnd();
    }

    // Draw sectors
    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        for (int j = 0; j < rings - 1; j++) {
            glVertex3fv(v[j * sectors + i]);
        }
        glEnd();
    }

    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        for (int j = rings - 1; j < 2 * rings - 3; j++) {
            glVertex3fv(v[j * sectors + i]);
        }
        glEnd();
    }
}
