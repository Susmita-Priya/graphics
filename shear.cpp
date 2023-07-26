#include <GL/gl.h>
#include <GL/glut.h>

void drawTriangle()
{

    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.2f, 0.0f);
    glVertex3f(0.8f, 0.8f, 0.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    // Draw the original triangle
    drawTriangle();

    glPushMatrix(); // Save the current transformation matrix

  // Apply horizontal shearing along x axis
    float shx = 1.3f;
    float shearMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        shx, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
     glMultMatrixf(shearMatrix);

    glColor3f(1.0f,0.0f,1.0f);
    // Draw the translated triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 2.0, -1.0, 2.0, -10.0, 10.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations on Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
