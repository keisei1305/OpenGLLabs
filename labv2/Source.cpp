#include <glut.h>
#include <cmath>

GLfloat light_position[] = { 0.0, 1.0, 1.0, 0.0 };
GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_shininess1 = { 0.0 };
GLfloat mat_shininess2 = { 10.0 };
GLfloat mat_shininess3 = { 120.0 };
GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat cubePostion[] = { -4.0, 0.5, -1.0 };
GLfloat light_angle = 0.0;
GLfloat light_pos[] = { 4, -0.5, 4, 1.0 };

void Quad(float x, float y, float z, float width, float height) {
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x, y + height, z);
    glEnd();
    glPopMatrix();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);

    glPushMatrix();
    glNormal3f(0, 0, 1);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess1);
    Quad(-5, 1.5, -2, 10, 1);

    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess2);
    Quad(-5, 0, -2, 10, 1);

    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess3);
    Quad(-5, -1.5, -2, 10, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(light_angle, 0.0, 1.0, 0.0);
    glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
    glColor3f(1.0, 1.0, 0.0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutIdleFunc(idle);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}