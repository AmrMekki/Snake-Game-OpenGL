//Jeff Chastine
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "game.h"

#define COLUMNS 40
#define ROWS 40

#define FPS 10

using namespace std;

extern short sDirection;
bool gameOver = false;
int score = 0;

void timerCallback(int);
void displayCallback();
void keyboardCallback(int, int, int);
void render();
void changeViewPort(int, int);

int main(int argc, char **argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600,600);
	glutCreateWindow("SNAKE GAME");
	glutDisplayFunc(displayCallback);
	glutReshapeFunc(changeViewPort);
	glutSpecialFunc(keyboardCallback);
	glutTimerFunc(100, timerCallback, 0);
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
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void render() {

	glClearColor(0,0,0,0);
	initGrid(COLUMNS, ROWS);
}


void displayCallback() {
	
	if (gameOver)
	{
		char _score[10];
		_itoa_s(score, _score,10);
		
		char text[50] = "Your score: ";
		string str1 = to_string(score);
		printf("Your score is: %d\n",score);
		MessageBox(NULL, L"", L"GAME OVER", MB_OK | MB_ICONQUESTION);
		exit(0);
	}

	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawFood();
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