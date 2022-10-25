#pragma once
#include "GLFW/glfw3.h"

namespace Napicu{
    class MouseEvent {

    private:
        static MouseEvent *mouseEvent;
        double xScroll, yScroll;
        double xPosition, yPosition, xLast, yLast;
        bool mouseButtonPressed[3] = {};
        bool isDragging;

        MouseEvent();

    public:

        static MouseEvent *get();

        static void mouseEventPositionCallback(GLFWwindow* window, double xPosition, double yPosition);

        static void mouseEventButtonCallback(GLFWwindow* window, int button, int action, int mods);

        static void mouseEventScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

        static void endFrame();

        static float getX() {return (float)get()->xPosition;}

        static float getY() {return (float)get()->yPosition;}

        static float getScrollX() {return (float)get()->xScroll;}

        static float getScrollY() {return (float)get()->yScroll;}

        static bool  getIsDragging() {return get()->isDragging;}
    };
}


