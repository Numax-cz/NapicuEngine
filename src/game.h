

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "Engine/window.h"
#include <GLFW/glfw3.h>


struct Game
{
    struct GLFWwindow *window;
    float last_frame, delta_time;
};

void napicu_game_run(struct Game *game);
void game_update();
void game_render();

#endif //OPENGL_GAME_H


