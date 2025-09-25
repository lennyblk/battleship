#include "ship.h"


void initShip(Ship* ship, int size, Coordinate position, int orientation) {
    ship->size = size;
    ship->hits = 0;
    ship->sunk = 0;
    ship->position = position;
    ship->orientation = orientation;
};

void initCoordinate(Coordinate* coord, int x, int y) {
    coord->x = x;
    coord->y = y;
};