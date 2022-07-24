

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include <GLFW/glfw3.h>
#include "Engine/window.h"


struct Game
{
    struct GLFWwindow *window;
    float last_frame, delta_time;
};

void napicu_game_run(struct Game* game);
void game_update(struct Game* game);
void game_render(struct Game* game);

#endif //OPENGL_GAME_H


