#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

float xMin, yMin, xMax, yMax,m,x1,y01,x2,y2;

int computeOutCode(float x, float y) {
    int code = INSIDE;
    if (x < xMin)
        code |= LEFT;
    else if (x > xMax)
        code |= RIGHT;
    if (y < yMin)
        code |= BOTTOM;
    else if (y > yMax)
        code |= TOP;
    return code;
}

void cohenSutherlandLineClip(float x1, float y01, float x2, float y2) {
    int outCode1 = computeOutCode(x1, y01);
    int outCode2 = computeOutCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outCode1 | outCode2)) {
            accept = true;
            break;
        }
        else if (outCode1 & outCode2) {
            break;
        }
        else {
            int outCodeOut = outCode1 ? outCode1 : outCode2;
            float x, y;

            if (outCodeOut & TOP) {
                x = x1 + (yMax - y01) / m;
                y = yMax;
            }
            else if (outCodeOut & BOTTOM) {
                x = x1 + (yMin - y01) / m;
                y = yMin;
            }
            else if (outCodeOut & RIGHT) {
                y = y01 + (xMax - x1) * m;
                x = xMax;
            }
            else if (outCodeOut & LEFT) {
                y = y01 + (xMin - x1) *m;
                x = xMin;
            }

            if (outCodeOut == outCode1) {
                x1 = x;
                y01 = y;
                outCode1 = computeOutCode(x1, y01);
            }
            else {
                x2 = x;
                y2 = y;
                outCode2 = computeOutCode(x2, y2);
            }
        }
    }

    if (accept) {
        glBegin(GL_LINES);
        glVertex2f(x1 / 100.0, y01 / 100.0);
        glVertex2f(x2 / 100.0, y2 / 100.0);
        glEnd();
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(xMin / 100.0, yMin / 100.0);
    glVertex2f(xMax / 100.0, yMin / 100.0);
    glVertex2f(xMax / 100.0, yMax / 100.0);
    glVertex2f(xMin / 100.0, yMax / 100.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(x1/100.0, y01/100.0);
    glVertex2f(x2/100.0, y2/100.0);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    cohenSutherlandLineClip(x1,y01,x2,y2);

    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char **argv) {
    std::cout << "Enter the coordinates of the clipping window (xMin yMin xMax yMax): " << std::endl;
    std::cin >> xMin >> yMin >> xMax >> yMax;
    std::cout << "Enter the points of line p1(x1,y1) ,p2(x2,y2): " << std::endl;
    std::cin >> x1 >> y01 >> x2 >> y2;
    m=(y2-y01)/(x2-x1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
