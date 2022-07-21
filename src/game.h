

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "GLFW/glfw3.h"

struct NapicuGame
{
    struct GLFWwindow* window;

    float delta_time;
    double last, now;

};

void game_init(struct NapicuGame* game);
void game_loop();
void game_destroy();

#endif //OPENGL_GAME_H
