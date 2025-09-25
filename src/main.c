#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"
#include "player/player.h" 
#include "config/config.h"

int main() {

    int ship_sizes[NB_SHIPS] = {2, 3, 4};

    Board* board = malloc(sizeof(Board));
    initBoard(board);
    
    Player player1;
    player1.board = board;
    player1.ships = malloc(NB_SHIPS * sizeof(Ship));
    player1.name = "Joueur 1";
    
    

    for (int i = 0; i < NB_SHIPS; i++) {
        player1.ships[i].size = ship_sizes[i];
        player1.ships[i].hits = 0;
        player1.ships[i].sunk = 0;
    }
    
    placeShips(&player1, NB_SHIPS);

    drawBoard(player1.board);
    free(player1.ships);
    free(board);
    return 0;

}