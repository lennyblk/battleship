#ifndef SHIP_H
#define SHIP_H

#include "../board/board.h"

typedef struct{
    Coordinate position;
    int size;
    int hits;
    int sunk;
    int orientation;
} Ship;

// Prototypes de fonctions
void initShip(Ship* ship, int size, Coordinate position, int orientation);
void initCoordinate(Coordinate* coord, int x, int y);

#endif

void initShip(Ship* ship, int size, Coordinate position, int orientation);

void initCoordinate(Coordinate* coord, int x, int y);