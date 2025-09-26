#ifndef GAME_H
#define GAME_H

#include "../player/player.h"

typedef struct {
    Player player1;
    Player player2;
} Game;

void initGame(Game* game);
int all_sunk(Player* player, int nb_ships);
#endif