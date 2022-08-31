#include <GL/glut.h>

float angle = 0.0f;
void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(
        0.0f, 0.0f, 10.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    );

    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-2.0f, -2.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glEnd();

    angle += 1.0f;

    glutSwapBuffers();
}

void changeSize(int w, int h)
{
    if (h == 0) h = 1;
    float ratio = w * 1.0f / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Main");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);

    glutIdleFunc(renderScene);

    glutMainLoop();

    return 1;
}
