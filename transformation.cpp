#include <GL/gl.h>
#include <GL/glut.h>

void drawTriangle()
{

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.25f, 0.5f, 0.0f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    // Draw the original triangle
    drawTriangle();

    glPushMatrix(); // Save the current transformation matrix

    // Apply translation
    glTranslatef(0.2f, 0.1f, 0.0f);

    glColor3f(1.0f, 0.0f, 1.0f);

    // Draw the translated triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glPushMatrix(); // Save the current transformation matrix

    // Apply scaling
    glScalef(1.5f, 0.8f, 0.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    // Draw the scaled triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glPushMatrix(); // Save the current transformation matrix

    glColor3f(0.0f, 1.0f, 1.0f);
    // Apply reflection by scaling in the Y-axis with a negative scaling factor
    glScalef(1.0f, -1.0f, 0.0f);

    // Draw the reflected triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glPushMatrix(); // Save the current transformation matrix

    glColor3f(0.0f, 1.0f, 0.0f);
    // Apply rotation (angle in degrees, rotation about the Z-axis)
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

    // Draw the rotated triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glPushMatrix(); // Save the current transformation matrix

    glColor3f(1.0f, 1.0f, 1.0f);
    // Apply horizontal shearing
    float shearX = 0.5f;
    float shearMatrix[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        shearX, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(shearMatrix);

    // Draw the horizontally sheared triangle
    drawTriangle();

    glPopMatrix(); // Restore the previous transformation matrix

    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
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
