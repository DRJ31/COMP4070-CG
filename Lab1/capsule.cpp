#include "drawings.h"

using namespace std;


void capsule() {
    vector<float *> v;
    vector<float *> cap;
    float radius = 0.15;
    float height = 0.8;
    int rings = 21;
    int sectors = 30;
    float x, y, z, l;

    // Get points for body
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

    // Get points for cap
    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < sectors; j++) {
            l = cos(asin(1.0 * i / rings)) * radius;
            x = cos(j * M_PI * 2 / sectors) * l;
            y = sin(j * M_PI * 2 / sectors) * l;
            z = height / 2 + i * radius / rings - height / rings;
            float *pos = new float[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
            cap.push_back(pos);
        }
    }

    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < sectors; j++) {
            l = cos(asin(1.0 * i / rings)) * radius;
            x = cos(j * M_PI * 2 / sectors) * l;
            y = sin(j * M_PI * 2 / sectors) * l;
            z = - height / 2 - i * radius / rings;
            float *pos = new float[3];
            pos[0] = x;
            pos[1] = y;
            pos[2] = z;
            cap.push_back(pos);
        }
    }

    // Draw rings
    for (int i = 0; i < rings; i++) {
        glBegin(GL_LINE_LOOP);
        if (i < rings / 2)
            glColor3f(1.0, 1.0, 0.0);
        else
            glColor3f(1.0, 0.0, 0.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(v[sectors * i + j]);
        }
        glEnd();
    }

    // Draw sectors
    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 0.0);
        for (int j = 0; j < rings / 2 + 1; j++) {
            glVertex3fv(v[sectors * j + i]);
        }
        glEnd();
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 0.0, 0.0);
        for (int j = rings / 2; j < rings; j++) {
            glVertex3fv(v[sectors * j + i]);
        }
        glEnd();
    }

    // Draw caps
    for (int i = 0; i < rings; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(cap[sectors * i + j]);
        }
        glEnd();
    }

    for (int i = rings; i < rings * 2; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 0.0);
        for (int j = 0; j < sectors; j++) {
            glVertex3fv(cap[sectors * i + j]);
        }
        glEnd();
    }

    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(0, 0, height / 2 + radius - height / rings);
        for (int j = rings - 1; j >= 0; j--) {
            glVertex3fv(cap[sectors * j + i]);
        }
        glEnd();
    }

    for (int i = 0; i < sectors; i++) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(0, 0, -height / 2 - radius);
        for (int j = rings * 2 - 1; j >= rings; j--) {
            glVertex3fv(cap[sectors * j + i]);
        }
        glEnd();
    }
}
