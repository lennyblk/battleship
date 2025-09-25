#ifndef SHIP_H
#define SHIP_H

#include <stdbool.h>
#include "../board/board.h"

typedef struct{
    Coordinate position;
    int size;
    int hits;
    int sunk;
    int orientation;
} Ship;

void initShip(Ship* ship, int size, Coordinate position, int orientation);
void initCoordinate(Coordinate* coord, int x, int y);
bool shoot(Ship* ships, int nb_ships, Board* board, int x, int y);

#endif