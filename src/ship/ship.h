#include "../board/board.h"

typedef struct{
    Coordinate position;
    int size;
    int hits;
    int sunk;
    int orientation;
} Ship;

void initShips(Ship* ships, int numShips);
