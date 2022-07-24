#include "game.h"


void napicu_game_run(struct Game* game){

    //Init
    game->window = window_init(1280, 720, "Window");
    game->delta_time = 0;


    while(!glfwWindowShouldClose(game->window)){
        window_poll_events();
        game_update(game);
        game_render(game);
        window_swap_buffers(game->window);
    }

    //Terminate
    window_close(game->window);
}

void game_update(struct Game* game){

}

void game_render(struct Game* game){

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

}









