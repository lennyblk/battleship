#include <stdio.h>
#include <stdlib.h>
#include "board/board.h"
#include "ship/ship.h"
#include "player/player.h"
#include "game/game.h"
#include "config/config.h"

int main() {
   Game* game = malloc(sizeof(Game));
   initGame(game); 
   
   
   
   return 0;
}