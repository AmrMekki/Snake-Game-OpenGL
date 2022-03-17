#include <GL\glew.h>
#include <GL\freeglut.h>
#include <ctime>
#include "game.h"

bool useGrid = false;

bool length_inc = false;
//bool seedflag = false;

extern int score;
extern bool gameOver;
bool food = true;

int gridX=0, gridY=0;
short sDirection = RIGHT;
int foodX, foodY;


int posX[MAX] = { 20,20,20,20,20 };
int posY[MAX] = { 20,19,18,17,16 };
int snakeLength = 5;

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void unit(int x, int y) {

	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
		glLineWidth(3);
		glColor3f(0.5, 0.5, 0.5);


		glBegin(GL_POLYGON);

		glVertex2f(x, y);
		glVertex2f(x + 1, y);
		glVertex2f(x + 1, y + 1);
		glVertex2f(x, y + 1);

		glEnd();
	}
	else {
		glLineWidth(1);
		glColor3f(1, 1, 1);
		if (useGrid) {
			glBegin(GL_LINE_LOOP);

			glVertex2f(x, y);
			glVertex2f(x + 1, y);
			glVertex2f(x + 1, y + 1);
			glVertex2f(x, y + 1);

			glEnd();
		}
	}
}

void drawGrid() {

	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++) {
			unit(x, y);
		}
	}
}



//changes
void drawSnake() {

	for(int i= snakeLength-1;i>0;i--){
		posX[i] = posX[i - 1];
		posY[i] = posY[i - 1];

	}
	if (sDirection == UP)
		posY[0]++;
	else if (sDirection == DOWN)
		posY[0]--;
	else if (sDirection == RIGHT)
		posX[0]++;
	else if (sDirection == LEFT)
		posX[0]--;
	for (int i = 0; i < snakeLength; i++) {

		if (i == 0)
			glColor3f(0, 0.5, 1);
		else
			glColor3f(0, 0.2, 0.2);

	glRectd(posX[i], posY[i], posX[i] + 1, posY[i] + 1);
	}

	if (posX[0] == 0 || posY[0] == 0 || posX[0] == gridX - 1 || posY[0] == gridY - 1)
		gameOver = true;
	else if (posX[0] == foodX && posY[0] == foodY) {
		
		score++;
		snakeLength++;
		if (snakeLength > MAX) {
			snakeLength = MAX;
			MessageBox(NULL, L"You Win\nYou can still keep playing but the snake will not grow.", L"Awsome", 0);
		}
		food = true;

	}
	else {
		for (int j = 1; j < snakeLength; j++)
		{
			if (posX[j] == posX[0] && posY[j] == posY[0])
				gameOver = true;
		}

	}
}

void drawFood() {
	if (food)
		random(foodX, foodY);
	food = false;
	glColor3f(0.7, 0.1, 0.7);
	glRectf(foodX, foodY, foodX + 1, foodY + 1);
}



void random(int& x, int& y) {

	int _maxX = gridX - 2;
	int _maxY = gridY - 2;
	int _min = 1;
	srand(time(NULL));
	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY - _min);
	
}