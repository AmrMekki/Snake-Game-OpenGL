#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


#define MAX 60

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2	


void initGrid(int, int);
void drawGrid();
void drawSnake();
void drawFood();
void random(int&, int&);
#endif // !GAME_H_INCLUDED
