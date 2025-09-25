#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "../config/config.h"

void initBoard(Board* board) {
    board->width = WIDTH;
    board->height = HEIGHT;
};
