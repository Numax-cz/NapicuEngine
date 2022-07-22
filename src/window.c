#include "window.h"

struct GLFWwindow* window_init(int width, int height, char* title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    struct GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(window);

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowPos(window, (mode->width - width) / 2, (mode->height - height) / 2);


//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, width, height, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

    return window;
}

void window_swap_buffers(struct GLFWwindow *window)
{
    glfwSwapBuffers(window);
}

void window_poll_events()
{
    glfwPollEvents();
}

void window_close()
{
    glfwTerminate();
}