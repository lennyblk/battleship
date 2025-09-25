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