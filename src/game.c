

#include "game.h"
#include "window.h"


void game_destroy(){
    window_close();
}



void game_update(){

}

void game_render(){


}


void game_start(struct NapicuGame* game){
    game->window = window_init(1280, 720, "OpenGLWindow");
    game->delta_time = 0;

    while(!glfwWindowShouldClose(game->window)){
        game->last = glfwGetTime();

        game_update();
        game_render();

        glfwSwapBuffers(game->window);
        game->now = glfwGetTime();
        game->delta_time = (float)(game->now - game->last) * 10.0f;
    }
    game_destroy();
}






