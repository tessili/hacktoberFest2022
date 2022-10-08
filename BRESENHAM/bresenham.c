#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void display(void)
{
    int dx, dy, p;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * (dy) - (dx);
    while (x1 <= x2)
    {
        if (p < 0)
        {
            x1 = x1 + 1;
            y1 = y1;
            p = p + 2 * (dy);
        }
        else
        {
            x1 = x1 + 1;
            y1 = y1 + 1;
            p = p + 2 * (dy - dx);
        }
        glBegin(GL_POINTS);
        glVertex2i(x1, y1);
        glEnd();
    }
    glFlush();
}

int main(int argc, char **argv)
{

    printf("Enter (x1, y1, x2, y2)\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}