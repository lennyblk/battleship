typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    int width;
    int height;
    char grid[10][10];
} Board;

void initBoard(Board* board);
void drawBoard(Board* board);
