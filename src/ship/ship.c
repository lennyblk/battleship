#include <stdio.h>
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

bool shoot(Ship* ships, int nb_ships, Board* board, int x, int y) {

    if (x < 0 || x >= board->width || y < 0 || y >= board->height) {
        return false;
    }
    
    for (int i = 0; i < nb_ships; i++) {
        Ship* ship = &ships[i];
        
        if (ship->sunk) {
            continue;
        }
        
        for (int j = 0; j < ship->size; j++) {
            int ship_x, ship_y;
            
            if (ship->orientation == 0) { 
                ship_x = ship->position.x + j;
                ship_y = ship->position.y;
            } else { 
                ship_x = ship->position.x;
                ship_y = ship->position.y + j;
            }
            
            if (ship_x == x && ship_y == y) {

                board->grid[y][x] = 'X'; 
                
                ship->hits++;
                
                if (ship->hits >= ship->size) {
                    ship->sunk = 1;
                    printf("Bateau coulé!\n");
                }
                
                return true; 
            }
        }
    }
    
    board->grid[y][x] = 'O'; 
    return false;
}