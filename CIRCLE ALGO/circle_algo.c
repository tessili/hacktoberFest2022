#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
int x1, y1, r;

// void plot(int x, int y)
//{
//	glBegin(GL_POINTS);
//		glVertex2i(x+x1, y+y1);
//	glEnd();
// }

void display(void)
{
    int x = 0;
    int y = r;
    int p = 1 - r;
    glBegin(GL_POINTS);
    glVertex2i(x + x1, y + y1);
    glEnd();

    while (y > x)
    {
        if (p < 0)
        {
            x++;
            p += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            p += 2 * (x - y) + 1;
        }
        glBegin(GL_POINTS);
        glVertex2i(x + x1, y + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(x + x1, -y + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(-x + x1, y + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(-x + x1, -y + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(y + x1, x + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(-y + x1, x + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(y + x1, -x + y1);
        glEnd();
        glBegin(GL_POINTS);
        glVertex2i(-y + x1, -x + y1);
        glEnd();
    }

    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv)
{
    printf("Enter the value of x1 : ");
    scanf("%d", &x1);
    printf("Enter the value of y1 : ");
    scanf("%d", &y1);
    printf("Enter the radius : ");
    scanf("%d", &r);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid Point Circle Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}