#pragma once

#include "../window.h"

namespace Napicu {
    class MouseEvent {

    private:
        inline static MouseEvent *mouseEvent;
        double xScroll, yScroll;
        double xPosition, yPosition, xLast, yLast;
        bool mouseButtonPressed[3] = {};
        bool isDragging;
        glm::vec2 screenViewportPosition, screenViewportSize;

        MouseEvent();

    public:


        static MouseEvent *get();

        static void mouseEventPositionCallback(GLFWwindow *window, double xPosition, double yPosition);

        static void mouseEventButtonCallback(GLFWwindow *window, int button, int action, int mods);

        static void mouseEventScrollCallback(GLFWwindow *window, double xOffset, double yOffset);

        static bool mouseButtonDown(int key);

        static void mouseButtonDownEvent(int key, const std::function<void()>& callBack);

        static bool inViewport(int x, int y);

        static void endFrame();

        static void setScreenViewportPosition(const glm::vec2& position);

        static void setScreenviewportSize(const glm::vec2& size);

        static float getOrthoX();

        static float getOrthoY();

        static glm::vec2  getOrthoPosition();

        static float getScreenX();

        static float getScreenY();

        static float getX() { return (float) get()->xPosition; }

        static float getY() { return (float) get()->yPosition; }

        static float getDx() { return (float) (get()->xLast - get()->xLast); }

        static float getDy() { return (float) (get()->yLast - get()->yLast); }

        static float getScrollX() { return (float) get()->xScroll; }

        static float getScrollY() { return (float) get()->yScroll; }

        static bool getIsDragging() { return get()->isDragging; }
    };
}


