#include "MouseEvent.h"

namespace Napicu{

    MouseEvent::MouseEvent() : xPosition(0), xLast(0), xScroll(0),
                               yPosition(0), yLast(0), yScroll(0) {}

    MouseEvent *MouseEvent::get() {
        if(MouseEvent::mouseEvent == nullptr) MouseEvent::mouseEvent = new MouseEvent();
        return MouseEvent::mouseEvent;
    }

    void MouseEvent::mouseEventPositionCallback(GLFWwindow* window, double xPosition, double yPosition) {
        get()->xLast = get()->xPosition;
        get()->yLast = get()->yPosition;
        get()->xPosition = xPosition;
        get()->yPosition = yPosition;
        get()->isDragging = get()->mouseButtonPressed[0] || get()->mouseButtonPressed[1] || get()->mouseButtonPressed[2];
    }

    void MouseEvent::mouseEventButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if(button < 3){
            if(action == GLFW_PRESS){
                get()->mouseButtonPressed[button] = true;
            }else if (action == GLFW_RELEASE){
                get()->mouseButtonPressed[button] = false;
                get()->isDragging = false;
            }
        }
    }

    void MouseEvent::mouseEventScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        get()->xScroll = xOffset;
        get()->yScroll = yOffset;
    }

    void MouseEvent::endFrame() {
        get()->xScroll = 0;
        get()->yScroll = 0;
        get()->xLast = get()->xPosition;
        get()->yLast = get()->yPosition;
    }
}