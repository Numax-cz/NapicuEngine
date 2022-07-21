

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <GLFW/glfw3.h>

struct GLFWwindow* window_init(int width, int height, char *title);
void window_swap_buffers(struct GLFWwindow *window);
void window_poll_events();
void window_close();

#endif //OPENGL_WINDOW_H
