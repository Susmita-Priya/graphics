#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include<bits/stdc++.h>

float x,y,x2,y2,m,dx,dy,inm;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POINTS);

    if(m>0.0&&m<=1.0)
    {

        while(x!=x2 && y!=y2)
        {
            glVertex3f(x/100, y/100, 0.0f);
            std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
            x=x+1;
            y=y+m;

        }
    }
    else if(m>=-1.0&&m<=0.0)
    {
        while(x!=x2 && y!=y2)
        {
            glVertex3f(x/100, y/100, 0.0f);
            std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
            x=x-1;
            y=y-m;
        }
    }
    else if(m>1)
    {
        while(x!=x2 && y!=y2)
        {
            glVertex3f(x/100, y/100, 0.0f);
            std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
            x=x+inm;
            y=y+1;

        }
    }
    else
    {
        while(x!=x2 && y!=y2)
        {
            glVertex3f(x/100, y/100, 0.0f);
            std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
            x=x-inm;
            y=y-1;

        }
    }
    glVertex3f(x2/100, y2/100, 0.0f);
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
    m=dy/dx;
    inm=1/m;
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
