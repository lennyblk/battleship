#ifndef PLAYER_H
#define PLAYER_H

#include "../board/board.h"
#include "../ship/ship.h"


typedef struct{
    Board* board;
    Ship* ships;
    char* name;
} Player;


void placeShips(Player* player, int nb_ships);
int placeShipOnBoard(Board* board, Ship* ship);
void initPlayer(Player* player);
void freePlayer(Player* player);

#endif
