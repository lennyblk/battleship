#include "../board/board.h"

typedef struct{
    Coordinate coordinate;
    int size;
    int hits;
    int sunk;
    int orientation;
} Ship;

