

#include "game.h"
#include "window.h"

void game_init(struct NapicuGame* game){
    game->window = window_init(1280, 720, "OpenGLWindow");
    game->delta_time = 0;
}

void game_destroy(){
    window_close();
}

void game_loop(struct NapicuGame* game){

    while(!glfwWindowShouldClose(game->window)){
        game->last = glfwGetTime();


        glfwSwapBuffers(game->window);
        game->now = glfwGetTime();
        game->delta_time = (float)(game->now - game->last) * 10.0f;
    }


}

