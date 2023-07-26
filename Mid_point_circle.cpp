#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include<bits/stdc++.h>

float x,y,r,p;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POINTS);

        glVertex3f(x/100.0, y/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
        glVertex3f(y/100.0, x/100.0, 0.0f);
        std::cout<<"("<<round(y)<<","<<round(x)<<")"<<std::endl;
        glVertex3f((-y)/100.0, (x)/100.0, 0.0f);
        std::cout<<"("<<round(-y)<<","<<round(x)<<")"<<std::endl;
        glVertex3f((-x)/100.0, (y)/100.0, 0.0f);
        std::cout<<"("<<round(-x)<<","<<round(y)<<")"<<std::endl;
        glVertex3f((-x)/100.0, (-y)/100.0, 0.0f);
        std::cout<<"("<<round(-x)<<","<<round(-y)<<")"<<std::endl;
        glVertex3f((-y)/100.0, (-x)/100.0, 0.0f);
        std::cout<<"("<<round(-y)<<","<<round(-x)<<")"<<std::endl;
        glVertex3f(y/100.0, (-x)/100.0, 0.0f);
        std::cout<<"("<<round(y)<<","<<round(-x)<<")"<<std::endl;
        glVertex3f(x/100.0, (-y)/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(-y)<<")"<<std::endl;
    while(x<y)
    {
      if(p<0)
      {
        x=x+1;
        y=y;
        p=p+(2*x)+1;
      }
     else
     {
        x=x+1;
        y=y-1;
        p=p+2*(x-y)+1;
     }

        glVertex3f(x/100.0, y/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(y)<<")"<<std::endl;
        glVertex3f(y/100.0, x/100.0, 0.0f);
        std::cout<<"("<<round(y)<<","<<round(x)<<")"<<std::endl;
        glVertex3f((-y)/100.0, (x)/100.0, 0.0f);
        std::cout<<"("<<round(-y)<<","<<round(x)<<")"<<std::endl;
        glVertex3f((-x)/100.0, (y)/100.0, 0.0f);
        std::cout<<"("<<round(-x)<<","<<round(y)<<")"<<std::endl;
        glVertex3f((-x)/100.0, (-y)/100.0, 0.0f);
        std::cout<<"("<<round(-x)<<","<<round(-y)<<")"<<std::endl;
        glVertex3f((-y)/100.0, (-x)/100.0, 0.0f);
        std::cout<<"("<<round(-y)<<","<<round(-x)<<")"<<std::endl;
        glVertex3f(y/100.0, (-x)/100.0, 0.0f);
        std::cout<<"("<<round(y)<<","<<round(-x)<<")"<<std::endl;
        glVertex3f(x/100.0, (-y)/100.0, 0.0f);
        std::cout<<"("<<round(x)<<","<<round(-y)<<")"<<std::endl;
    }

    glEnd();

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

    std::cout<<"Enter radius : "<<std::endl;
    std::cin>>r;
    x=0;
    y=r;
    p=1-r;

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

