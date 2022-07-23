#include "game.h"

void napicu_game_run(struct Game* game){

    //Init
    window_init(game->window);



    while(!glfwWindowShouldClose(game->window)){


    }

    //Terminate
    window_close();
}

void game_update(){

}

void game_render(){

}









