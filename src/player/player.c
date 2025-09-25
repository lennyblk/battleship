#include <stdio.h>
#include <stdlib.h>
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

