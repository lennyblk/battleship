#include <stdio.h>
#include <stdlib.h>
#include "../board/board.h"
#include "../ship/ship.h"
#include "../player/player.h"
#include "game.h"
#include <string.h>

void initGame(Game* game) {
    initPlayer(&game->player1);
    initPlayer(&game->player2);
}


int all_sunk(Player* player, int nb_ships) {
    int all_sunk = 1;
    for (int i = 0; i < nb_ships; i++) {
        if (!player->ships[i].sunk) {
            all_sunk = 0;
            break;
        }
    }
    return all_sunk;
}
