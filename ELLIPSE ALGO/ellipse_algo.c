#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
int x1, y1, rx, ry;

// void plot(int x, int y)
//{
//	glBegin(GL_POINTS);
//		glVertex2i(x+x1, y+y1);
//	glEnd();
// }

void display(void)
{
    int x, y;
    float p;

    // region 1
    p = (ry * ry) - (rx * rx * ry) + (rx * rx * 1 / 4);
    x = 0;
    y = ry;
    while (2 * ry * ry * x <= 2 * rx * rx * y)
    {
        if (p < 0)
        {
            x++;
            p = p + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x++;
            y--;
            p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
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
    }

    // region 2
    p = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
    while (y > 0)
    {
        if (p <= 0)
        {
            x++;
            y--;
            p = p + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            y--;
            p = p - (2 * rx * rx * y) + (rx * rx);
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
    printf("Enter (x,y) of radius : ");
    scanf("%d%d", &rx, &ry);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid Point Ellipse Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}