#include "drawings.h"

using namespace std;


void koch_snowfake() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0 * 0.8, -1 / sqrt(3) * 0.8);
    glVertex2f(1.0 * 0.8, -1 / sqrt(3) * 0.8);
    glVertex2f(0.0, 2 / sqrt(3) * 0.8);
    glEnd();
}
