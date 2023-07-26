#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.0,1.0);


/// for square
    glBegin(GL_POLYGON);

    glVertex3f(0.02f,0.02f,0.0f);
    glVertex3f(0.02f,0.35f,0.0f);
    glVertex3f(0.5f,0.35f,0.0f);
    glVertex3f(0.5f,0.02f,0.0f);

    glEnd();


/// for triangle
    glBegin(GL_TRIANGLES);

    glColor3f(0.0,1.0,0.0);
    glVertex3f(0.02f,0.35f,0.0f);
    glVertex3f(0.5f,0.35f,0.0f);
    glVertex3f(0.25f,0.5f,0.0f);

    glEnd();

/// for circle
    int segment=100;
    float radius=0.1f;
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_TRIANGLE_FAN);
    for (int i=1;i<=100;i++)
    {
        float theta= 2.0f * 3.1416f * float(i)/float(segment);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex3f(x+0.65f, y+0.65f,0.0f);

    }
    glEnd();

/// for lines
    glBegin(GL_LINES);

    glVertex2f(0.35f,0.85f);
    glVertex2f(0.5f,0.85f);

    glEnd();

    glFlush();
}

void init(void){

    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Basic shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

