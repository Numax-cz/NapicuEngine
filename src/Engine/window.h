

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include "include/GLFW/glfw3.h"
#include <GL/gl.h>



struct napicu_window{
 int width;
 int height;
 char *title;
};

struct GLFWwindow* window_init(struct GLFWwindow* window);

void window_swap_buffers(struct GLFWwindow* window);
void window_poll_events();
void window_close();

#endif //OPENGL_WINDOW_H
