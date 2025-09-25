#ifndef PLAYER_H
#define PLAYER_H

#include "../board/board.h"
#include "../ship/ship.h"


typedef struct{
    Board* board;
    Ship* ships;
    char* name;
} Player;

void initPlayer(Player* player);

#endif