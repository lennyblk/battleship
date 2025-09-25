#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"


void placeShips(Player* player, int nb_ships) {
    for (int i = 0; i < nb_ships; i++) {
        Ship* ship = &player->ships[i];
        bool placed = false;
        
        while (!placed) {
            printf("\n=== Placement du bateau %d (taille %d) ===\n", i + 1, ship->size);
            drawBoard(player->board);
            
            int x, y, orientation;  
            
            printf("Entrez la position x (0-%d): ", player->board->width - 1);
            fflush(stdout);
            if (scanf("%d", &x) != 1) {
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
                while (getchar() != '\n');
                continue;
            }
            
            printf("Entrez la position y (0-%d): ", player->board->height - 1);
            fflush(stdout);
            if (scanf("%d", &y) != 1) {
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
                while (getchar() != '\n');
                continue;
            }
            
            printf("Entrez l'orientation (0=horizontal, 1=vertical): ");
            fflush(stdout);
            if (scanf("%d", &orientation) != 1 || (orientation != 0 && orientation != 1)) {
                printf("Entrée invalide. Veuillez entrer 0 ou 1.\n");
                while (getchar() != '\n');
                continue;
            }
            
            while (getchar() != '\n');
            
            if (x < 0 || x >= player->board->width || y < 0 || y >= player->board->height) {
                printf("Position hors limites ! Veuillez réessayer.\n");
                continue;
            }
            
            Coordinate position;
            initCoordinate(&position, x, y);
            initShip(ship, ship->size, position, orientation);

            if (placeShipOnBoard(player->board, ship)) {
                printf("\n✅ Bateau %d placé avec succès !\n", i + 1);
                drawBoard(player->board);
                placed = true;
            } else {
                printf("❌ Impossible de placer le bateau à cette position. Réessayez.\n");
            }
        }
    }
    
    printf("\n🎉 Tous les bateaux ont été placés avec succès !\n");
}

int placeShipOnBoard(Board* board, Ship* ship) {
    for (int i = 0; i < ship->size; i++) {
        int x = ship->position.x + (ship->orientation == 0 ? i : 0);
        int y = ship->position.y + (ship->orientation == 1 ? i : 0);
        
        if (x < 0 || x >= board->width || y < 0 || y >= board->height) {
            printf("Le bateau dépasse les limites du plateau à la position (%d, %d)\n", x, y);
            return 0;
        }
        
        if (board->grid[y][x] != '-') {
            printf("La position (%d, %d) est déjà occupée (case: '%c')\n", x, y, board->grid[y][x]);
            return 0;
        }
    }

    for (int i = 0; i < ship->size; i++) {
        int x = ship->position.x + (ship->orientation == 0 ? i : 0);
        int y = ship->position.y + (ship->orientation == 1 ? i : 0);
        board->grid[y][x] = 'S'; 
    }
    
    return 1;
}
#include <string.h>
#include "player.h"

void initPlayer(Player* player) {
    printf("Entrez le nom du joueur: ");
    char* name = malloc(100 * sizeof(char));

    scanf("%99s", name); 
    player->name = malloc(strlen(name) + 1);
    strcpy(player->name, name);

    Board* board = malloc(sizeof(Board));
    initBoard(board);
    player->board = board;

}

