#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"

int main() {
    Board* board = malloc(sizeof(Board));
    initBoard(board);

    Ship ships[3];
    
    Coordinate coord1;
    initCoordinate(&coord1, 0, 0);
    initShip(&ships[0], 3, coord1, 0);
    
    Coordinate coord2;
    initCoordinate(&coord2, 5, 2);
    initShip(&ships[1], 4, coord2, 1);
    
    Coordinate coord3;
    initCoordinate(&coord3, 2, 7);
    initShip(&ships[2], 2, coord3, 0);

    printf("=== Test de la fonction shoot ===\n\n");
    
    printf("Test 1 - Tir en (1,0): ");
    bool hit1 = shoot(ships, 3, board, 1, 0);
    printf("%s\n", hit1 ? "TOUCHÉ!" : "Raté");
    
    printf("Test 2 - Tir en (9,9): ");
    bool hit2 = shoot(ships, 3, board, 9, 9);
    printf("%s\n", hit2 ? "TOUCHÉ!" : "Raté");
    
    printf("Test 3 - Tir en (5,3): ");
    bool hit3 = shoot(ships, 3, board, 5, 3);
    printf("%s\n", hit3 ? "TOUCHÉ!" : "Raté");
    
    printf("\nTest 4 - Couler le bateau 3:\n");
    printf("Tir en (2,7): ");
    bool hit4a = shoot(ships, 3, board, 2, 7);
    printf("%s\n", hit4a ? "TOUCHÉ!" : "Raté");
    
    printf("Tir en (3,7): ");
    bool hit4b = shoot(ships, 3, board, 3, 7);
    printf("%s\n", hit4b ? "TOUCHÉ!" : "Raté");
    
    printf("\n=== État du plateau après les tirs ===\n");
    drawBoard(board);
    
    printf("\n=== État des bateaux ===\n");
    for (int i = 0; i < 3; i++) {
        printf("Bateau %d: Position(%d,%d), Taille=%d, Touches=%d, Coulé=%s\n", 
               i+1, ships[i].position.x, ships[i].position.y, ships[i].size, 
               ships[i].hits, ships[i].sunk ? "OUI" : "NON");
    }

    free(board);
    return 0;
}