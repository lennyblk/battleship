#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"
#include "player/player.h" 
#include "config/config.h"

int main() {

    int ship_sizes[NB_SHIPS] = {2, 3, 4};


    Player* player1 = malloc(sizeof(Player));
    initPlayer(player1);

    player1->ships = malloc(NB_SHIPS * sizeof(Ship));

    for (int i = 0; i < NB_SHIPS; i++) {
        player1->ships[i].size = ship_sizes[i];
        player1->ships[i].hits = 0;
        player1->ships[i].sunk = 0;
    }
    
    placeShips(player1, NB_SHIPS);


    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Au tour du joueur 2 de placer ses bateaux.\n");


    
    Player* player2 = malloc(sizeof(Player));
    initPlayer(player2);

    player2->ships = malloc(NB_SHIPS * sizeof(Ship));

    for (int i = 0; i < NB_SHIPS; i++) {
        player2->ships[i].size = ship_sizes[i];
        player2->ships[i].hits = 0;
        player2->ships[i].sunk = 0;
    }
    
    placeShips(player2, NB_SHIPS);

    int gagnant = 0;
    while(gagnant == 0) {
        
        int all_sunk = 1;

        while(shoot(player2->ships, NB_SHIPS, player2->board)) {
            printf("Touché!\n");
            for (int i = 0; i < NB_SHIPS; i++) {
                if (!player2->ships[i].sunk) {
                    all_sunk = 0;
                    break;
                }
            }
            if (all_sunk) {
                gagnant = 1;
                break;
            }
        } 
        printf("Manqué!\n");
        
        drawBoard(player2->board);

        all_sunk = 1;
        while (shoot(player1->ships, NB_SHIPS, player1->board)) {
            printf("Touché!\n");
            for (int i = 0; i < NB_SHIPS; i++) {
                if (!player1->ships[i].sunk) {
                    all_sunk = 0;
                    break;
                }
            }
            if (all_sunk) {
                gagnant = 2;
                break;
            }
        }
        printf("Manqué!\n");

        drawBoard(player1->board);

        
        
    }
    printf("Le joueur %d a gagné ! Félicitations %s!\n", gagnant, gagnant == 1 ? player1->name : player2->name);

    free(player1->ships);
    free(player1->board);
    free(player1);
    free(player2->ships);
    free(player2->board);
    free(player2);
    return 0;

}