#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"
#include "player/player.h" 
#include "config/config.h"
#include "game/game.h"

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

    clearScreen();

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

    clearScreen();
    printf("Début de la partie !\n");
    int gagnant = 0;
    while(gagnant == 0) {
        
        while(shoot(player2->ships, NB_SHIPS, player2->board, player1->name)) {
            clearScreen();
            printf("Touché!\n");
            drawBoardEnemy(player2->board);
            if (all_sunk(player2, NB_SHIPS)) {
                gagnant = 1;
                break;
            }
        } 
        if(gagnant != 0) break;
        
        clearScreen();
        printf("Manqué!\n");

        drawBoardEnemy(player2->board);
        printf("Au tour de player 2 : Cliquez sur une touche et appuyez sur Entrée pour voir votre plateau.\n");
        fflush(stdin);
        char dummy;
        scanf(" %c", &dummy);

        drawBoard(player2->board);
        clearScreen();

        while (shoot(player1->ships, NB_SHIPS, player1->board, player2->name)) {
            printf("Touché!\n");
            drawBoardEnemy(player1->board);
            if (all_sunk(player1, NB_SHIPS)) {
                gagnant = 2;
                break;
            }
        }
        if(gagnant != 0) break;
        clearScreen();
        printf("Manqué!\n");

        drawBoard(player1->board);

        drawBoardEnemy(player1->board);
        printf("Au tour de player 1 : Cliquez sur une touche et appuyez sur Entrée pour voir votre plateau.\n");
        fflush(stdin);
        scanf(" %c", &dummy);


    }
    printf("Le joueur %d a gagné ! Félicitations %s!\n", gagnant, gagnant == 1 ? player1->name : player2->name);

    freePlayer(player1);
    free(player1);
    freePlayer(player2);
    free(player2);
    
    return 0;

}