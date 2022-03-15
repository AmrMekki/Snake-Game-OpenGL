//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

void displayCallback();
void render();
void changeViewPort(int, int);

int main(int argc, char **argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	//glutInitWindowPosition(200, 100);
	glutInitWindowSize(500,500);
	glutCreateWindow("SNAKE");
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(changeViewPort);
	render();
	glutMainLoop();




	
	return 0;
}

void changeViewPort(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,40,0,40,-1,1);
}

void render() {

	glClearColor(1,0,0,1);
}

void displayCallback() {

	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}