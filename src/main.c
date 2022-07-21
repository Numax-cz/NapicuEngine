#include <stdio.h>
#include "window.h"
#include "game.h"

int main() {


    struct NapicuGame game;

    game_init(&game);
    game_loop();
    game_destroy();

    return 0;
}
