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
    char grid[WIDTH][HEIGHT];
} Board;

void initBoard(Board* board);
void drawBoard(Board* board);

#endif
