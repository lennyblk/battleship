#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define WIDTH 10
#define HEIGHT 10

void initBoard(Board* board) {
    board->width = WIDTH;
    board->height = HEIGHT;
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board->grid[i][j] = '-';
        }
    }
}

void drawBoard(Board* board) {
    printf("\n");
    printf("  ");
    for (int i = 0; i < board->width; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < board->height; i++) {
        printf("%d ", i);
        for (int j = 0; j < board->width; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}