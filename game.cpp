#include <GL\glew.h>
#include <GL\freeglut.h>

#include "game.h"

int gridX, gridY;
short sDirection = RIGHT;

int posX = 20, posY = 20;

void initGrid(int x, int y) {
	gridX = x;
	gridY = y;
}

void unit(int x, int y) {

	if (x == 0 || y == 0 || x == gridX - 1 || y == gridY - 1) {
		glLineWidth(3);
		glColor3f(1, 0, 0);
	}
	else{
		glLineWidth(1);
		glColor3f(1, 1, 1);
	}
	glBegin(GL_LINE_LOOP);

	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);

	glEnd();
}

void drawGrid() {

	for (int x = 0; x < gridX; x++)
	{
		for (int y = 0; y < gridY; y++) {
			unit(x, y);
		}
	}
}


void drawSnake() {
	if (sDirection == UP)
		posY++;
	else if (sDirection == DOWN)
		posY--;
	else if (sDirection == RIGHT)
		posX++;
	else if (sDirection == LEFT)
		posX--;

	glRectd(posX, posY, posX+1, posY+1);

}