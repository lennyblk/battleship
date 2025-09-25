#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"

int main() {
    Board* board = malloc(sizeof(Board));
    initBoard(board);

    Ship* ship = malloc(sizeof(Ship));

    Coordinate* coord = malloc(sizeof(Coordinate));
    initCoordinate(coord, 0, 0);
    
    initShip(ship, 5, *coord, 0);

    for(int i = 0; i < ship->size; i++) {
        printf("Ship part %d at (%d, %d)\n", i, ship->position.x + (ship->orientation == 0 ? i : 0), ship->position.y + (ship->orientation == 1 ? i : 0));
    }

    free(board);
    free(ship);
    free(coord);

    return 0;
}