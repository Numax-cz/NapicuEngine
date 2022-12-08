#include "MouseEvent.h"


namespace Napicu {

    MouseEvent::MouseEvent() : xPosition(0), xLast(0), xScroll(0),
                               yPosition(0), yLast(0), yScroll(0) {}

    MouseEvent *MouseEvent::get() {
        if (MouseEvent::mouseEvent == nullptr) MouseEvent::mouseEvent = new MouseEvent();
        return MouseEvent::mouseEvent;
    }

    bool MouseEvent::mouseButtonDown(int key) {
        return get()->mouseButtonPressed[key];
    }

    void MouseEvent::mouseButtonDownEvent(int key, const std::function<void()>& callBack) {
        if(get()->mouseButtonPressed[key]) {
            callBack();
            get()->mouseButtonPressed[key] = false;
        }
    }

    void MouseEvent::mouseEventPositionCallback(GLFWwindow *window, double xPosition, double yPosition) {
        get()->xLast = get()->xPosition;
        get()->yLast = get()->yPosition;
        get()->xPosition = xPosition;
        get()->yPosition = yPosition;
        get()->isDragging = get()->mouseButtonPressed[0]
                        || get()->mouseButtonPressed[1]
                        || get()->mouseButtonPressed[2];
    }

    void MouseEvent::mouseEventButtonCallback(GLFWwindow *window, int button, int action, int mods) {
        if (button < 3) {
            if (action == GLFW_PRESS) {
                get()->mouseButtonPressed[button] = true;
            } else if (action == GLFW_RELEASE) {
                get()->mouseButtonPressed[button] = false;
                get()->isDragging = false;
            }
        }
    }

    void MouseEvent::mouseEventScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
        get()->xScroll = xOffset;
        get()->yScroll = yOffset;
    }

    void MouseEvent::endFrame() {
        get()->xScroll = 0;
        get()->yScroll = 0;
        get()->xLast = get()->xPosition;
        get()->yLast = get()->yPosition;
    }

    float MouseEvent::getScreenX() {
        return ((MouseEvent::getX() - MouseEvent::get()->screenViewportPosition.x) / MouseEvent::get()->screenViewportSize.x) * Napicu::Window::SCREEN_SIZE_X;
    }

    float MouseEvent::getScreenY() {
        return Napicu::Window::SCREEN_SIZE_Y - (((MouseEvent::getY() - MouseEvent::get()->screenViewportPosition.y) / MouseEvent::get()->screenViewportSize.y) * Napicu::Window::SCREEN_SIZE_Y);
    }

    float MouseEvent::getOrthoX() {
        glm::mat4 invMat = Window::current_scene->getCamera().getViewProjectionMatrixInverse();
        glm::vec4 near = glm::vec4(((MouseEvent::getX() - MouseEvent::get()->screenViewportPosition.x) / MouseEvent::get()->screenViewportSize.x) * 2 - 1, 0, 0, 1.0);
        glm::vec4 nearResult = invMat * near;
        return nearResult.x;
    }

    float MouseEvent::getOrthoY() {
        glm::mat4 invMat = Window::current_scene->getCamera().getViewProjectionMatrixInverse();
        glm::vec4 near = glm::vec4(0, -(((MouseEvent::getY() - MouseEvent::get()->screenViewportPosition.y ) / MouseEvent::get()->screenViewportSize.y) * 2 - 1), 0, 1.0);
        glm::vec4 nearResult = invMat * near;
        return nearResult.y;
    }

    glm::vec2 MouseEvent::getOrthoPosition() {
        return glm::vec2(MouseEvent::getOrthoX(), MouseEvent::getOrthoY());
    }

    void MouseEvent::setScreenViewportPosition(const glm::vec2& position) {
        MouseEvent::get()->screenViewportPosition = position;
    }

    void MouseEvent::setScreenviewportSize(const glm::vec2& size) {
        MouseEvent::get()->screenViewportSize = size;
    }

    bool MouseEvent::inViewport(int x, int y) {
        return (x > 0 && y < Napicu::Config::CAMERA_PROJECTION_SIZE_Y && y > 0);
    }
}