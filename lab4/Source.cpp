#include <glut.h>
#include <cmath>

GLfloat light_angle = 0.0; // Угол вращения источника света
GLfloat light_pos[] = { 4, 0.0, 4, 1.0 }; // Положение источника света

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, 8.0, 8.0,  // Положение камеры
        0.0, 0.0, 0.0,   // Направление, куда смотрит камера
        0.0, 1.0, 0.0);  // Направление верха камеры

    glPushMatrix();
    glTranslatef(-4.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCone(1.0, 2.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(2.0);
    glPopMatrix();

    glPushMatrix();
    glRotatef(light_angle, 0.0, 1.0, 0.0);
    glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidSphere(0.1, 20, 20);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    light_angle += 0.5;
    if (light_angle > 360.0)
        light_angle -= 360.0;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("OpenGL rotating light source");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
    return 0;
}