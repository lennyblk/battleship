#ifndef BOARD_H
#define BOARD_H

#include "../config/config.h"

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct{
    int width;
    int height;
    char grid[HEIGHT][WIDTH];
} Board;

void initBoard(Board* board);
void drawBoard(Board* board);
void drawBoardEnemy(Board* board);

#endif
