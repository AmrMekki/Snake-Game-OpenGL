//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include "game.h"

#define COLUMNS 40
#define ROWS 40

#define FPS 10

using namespace std;

extern short sDirection;

void timerCallback(int);
void displayCallback();
void keyboardCallback(int, int, int);
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
	glutTimerFunc(0, timerCallback, 0);
	glutSpecialFunc(keyboardCallback);
	render();
	glutMainLoop();




	
	return 0;
}

void timerCallback(int ) {

	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timerCallback, 0);

}

void changeViewPort(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,COLUMNS,0,ROWS,-1,1);
}

void render() {

	glClearColor(0,0,0,1);
	initGrid(COLUMNS, ROWS);
}

void displayCallback() {

	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	glutSwapBuffers();
}


void keyboardCallback(int key, int, int) {

	switch (key) {
	case GLUT_KEY_UP:
		if (sDirection != DOWN)
			sDirection = UP;
		break;
	case GLUT_KEY_DOWN:
		if (sDirection != UP)
			sDirection = DOWN;
		break;
	case GLUT_KEY_RIGHT:
		if (sDirection != LEFT)
			sDirection = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (sDirection != RIGHT)
			sDirection = LEFT;
		break;

	}

}