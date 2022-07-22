

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "GLFW/glfw3.h"

struct NapicuGame
{
    struct GLFWwindow* window;

    float delta_time;
    double last, now;

};

void game_start(struct NapicuGame* game);
void game_update();
void game_render();
#endif //OPENGL_GAME_H
