//susmita saha

#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

void drawsquare(float sx,float sy)
{
    glColor3f(1.0f,0.0f,1.0f);

    glBegin(GL_QUADS);
    glVertex3f(0.02f*sx, 0.02f*sy, 0.0f);
    glVertex3f(0.02f*sx, 0.35f*sy, 0.0f);
    glVertex3f(0.5f*sx, 0.35f*sy, 0.0f);
    glVertex3f(0.5f*sx, 0.02f*sy, 0.0f);
    glEnd();

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
    glVertex3f(0.02f, 0.02f, 0.0f);
    glVertex3f(0.02f, 0.35f, 0.0f);
    glVertex3f(0.5f, 0.35f, 0.0f);
    glVertex3f(0.5f, 0.02f, 0.0f);
    glEnd();

    float sx=0.8f;
    float sy=0.8f;

    glPushMatrix(); // Save the current transformation matrix
    glScalef(sx, sy, 0.0f); // Apply translation

    // Draw the square
    drawsquare(sx,sy);

    glPopMatrix(); // Restore the previous transformation matrix

    glFlush();

}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Basic shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

