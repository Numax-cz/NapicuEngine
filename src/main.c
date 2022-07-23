#include <stdio.h>
#include "Engine/window.h"
#include "game.h"

int main() {


    struct napicu_window game_window = {1280, 720, "NapicuGame"};

    napicu_game_run(game_window);




    //game_start(&game)

    return 0;
}
