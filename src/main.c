#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"

int main() {
    Board* board = malloc(sizeof(Board));
    
    initBoard(board);
    drawBoard(board);

    free(board);
    return 0;
}