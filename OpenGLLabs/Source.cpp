#include <iostream>
#include <glut.h>
#include <map>
#pragma comment (lib, "opengl32.lib")

using namespace std;

float WinWid = 1200, WinHei = 800;

float angle = 0.0, scale = 1.0;

void timer(int value) {

	glColor3f(1.0, 0.0, 1.0);

	angle++;

	glRotatef(6, 0, 0, 1);

	glutPostRedisplay();

	glutTimerFunc(70, timer, 0);

}

void init() {

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(60, 1200 / 800, 0.1, 30.0);
	glTranslatef(-2.0, -0.5, -15.0);
	glRotatef(90, 1, 0, 0);

	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

void drawTors() {
	glColor3f(0.68f, 0.33f, 0.18f);
	glTranslatef(0, 0, 0);
	gluSphere(gluNewQuadric(), 1.7, 1000, 1000);

	glTranslatef(0, 0, -1);
	gluSphere(gluNewQuadric(), 2, 1000, 1000);
}

void drawHead() {
	glColor3f(0.68f, 0.33f, 0.18f);
	glTranslatef(0, 0, -3);
	gluSphere(gluNewQuadric(), 1.7, 1000, 1000);
}

void drawEyes() {
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1, 2, -6);
	gluSphere(gluNewQuadric(), 0.3, 1000, 1000);
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 0.25, 0);
	gluSphere(gluNewQuadric(), 0.1, 1000, 1000);

	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.3, -0.3, 0);
	gluSphere(gluNewQuadric(), 0.3, 1000, 1000);
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 0.25, 0);
	gluSphere(gluNewQuadric(), 0.1, 1000, 1000);
}

void drawMouthAndNose() {
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-0.6, 0, 1);
	gluSphere(gluNewQuadric(), 0.6, 1000, 1000);
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0, 0.5, -0.2);
	gluSphere(gluNewQuadric(), 0.2, 1000, 1000);
}

void drawFace() {
	drawEyes();
	drawMouthAndNose();
}

void drawEars() {
	glColor3f(0.68f, 0.33f, 0.18f);
	glTranslatef(1.5, 0, -1.1);
	gluSphere(gluNewQuadric(), 0.5, 1000, 1000);

	glTranslatef(-3, 0, 0);
	gluSphere(gluNewQuadric(), 0.5, 1000, 1000);
}

void drawArms() {
	glColor3f(0.68f, 0.33f, 0.18f);
	glTranslatef(3.2, 0, 3.2);
	gluSphere(gluNewQuadric(), 0.5, 1000, 1000);
	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1.6, 20, 20);
	glTranslatef(0, 0, 1.6);
	gluSphere(gluNewQuadric(), 0.6, 1000, 1000);

	glTranslatef(-3.2, 0, -1.6);
	gluSphere(gluNewQuadric(), 0.5, 1000, 1000);
	gluCylinder(gluNewQuadric(), 0.5, 0.5, 1.6, 20, 20);
	glTranslatef(0, 0, 1.6);
	gluSphere(gluNewQuadric(), 0.6, 1000, 1000);
}

void drawLegs() {
	glColor3f(0.68f, 0.33f, 0.18f);
	glTranslatef(2.2, -0.5, 1.4);
	gluSphere(gluNewQuadric(), 0.7, 1000, 1000);
	gluCylinder(gluNewQuadric(), 0.7, 0.7, 1, 20, 20);
	glTranslatef(0, 0, 1);
	gluSphere(gluNewQuadric(), 0.75, 1000, 1000);

	glTranslatef(-2.2, 0, -1);
	gluSphere(gluNewQuadric(), 0.7, 1000, 1000);
	gluCylinder(gluNewQuadric(), 0.7, 0.7, 1, 20, 20);
	glTranslatef(0, 0, 1);
	gluSphere(gluNewQuadric(), 0.75, 1000, 1000);
}

void drawBear() {
	glPushMatrix();
	drawTors();
	drawHead();
	drawEars();
	drawArms();
	drawLegs();
	drawFace();
	glPopMatrix();
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	//glRotatef(angle, 0.0, 0.0, 1.0);

	drawBear();

	glPopMatrix();

	glutSwapBuffers();

}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(WinWid, WinHei);

	glutInitWindowPosition(400, 150);

	glutCreateWindow("Window");

	glutDisplayFunc(draw);

	glutTimerFunc(60, timer, 0);

	init();

	glutMainLoop();
}