#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include<bits/stdc++.h>

float x,y,x2,y2,p,dx,dy;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POINTS);

    while(x!=x2 && y!=y2)
    {
      if(p<0)
      {
        glVertex3f(x/100.0, y/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
        x=x+1;
        y=y;
        p=p+(2*dy);
      }
     else
     {
        glVertex3f(x/100.0, y/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
        x=x+1;
        y=y+1;
        p=p+2*(dy-dx);
     }
    }
    glVertex3f(x2/100.0, y2/100.0, 0.0f);
    std::cout<<"("<<round(x2)<<","<<round(y2)<<")"<<std::endl;

    glEnd();

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

    std::cout<<"Enter first point p(X1,y1)"<<std::endl;
    std::cin>>x>>y;
    std::cout<<"Enter second point p(X2,y2)"<<std::endl;
    std::cin>>x2>>y2;
    dy=y2-y;
    dx=x2-x;
    p=(2*dy)-dx;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Basic shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
