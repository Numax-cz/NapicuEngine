#include "window.h"

struct GLFWwindow* window_init(int width, int height, const char *title){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    struct GLFWwindow* glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    glfwMakeContextCurrent(glfwWindow);

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    glfwSetWindowPos(glfwWindow, (mode->width - width) / 2, (mode->height - height) / 2);


    glfwSwapInterval(1); //V-Sync
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, width, height, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();



    return glfwWindow;
}

void window_swap_buffers(struct GLFWwindow *window){
    glfwSwapBuffers(window);
}

void window_poll_events(){
    glfwPollEvents();
}

void window_close(struct GLFWwindow* window){
    glfwDestroyWindow(window);
    glfwTerminate();
}