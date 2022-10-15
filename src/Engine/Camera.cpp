#include "Camera.h"

namespace Napicu{
    Camera::Camera(float left, float right, float bottom, float top)
        : pMatrix(glm::ortho(left, right, bottom, top, 0.0f, 100.0f)), vMatrix(1.0f){
        this->vPMatrix = this->pMatrix * this->vMatrix;
    }

    void Camera::recalculateVMatrix() {
        glm::mat4 tr = glm::translate(glm::mat4(1.0f), this->position)
                * glm::rotate(glm::mat4(1.0f), this->rotation, glm::vec3(0,0,-1.0f));
        this->vMatrix = glm::inverse(tr);
        this->vPMatrix = this->pMatrix * this->vMatrix;
    }
}