#include "Camera.h"
#include <iostream>

namespace Napicu {
    Camera::Camera(float left, float right, float bottom, float top)
            : left(left), right(right), bottom(bottom), top(top), vMatrix(1.0f) {
        this->recalculateVMatrix();
    }

    void Camera::recalculateVMatrix() {
        pMatrix = glm::ortho(left, right * this->zoom,
                             bottom, top * this->zoom,
                             0.0f, 100.0f);

        glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        this->vMatrix = {};
        this->vMatrix = glm::lookAt(
                glm::vec3(this->position.x, this->position.y, 20.0f),
                cameraFront + glm::vec3(this->position.x, this->position.y, 0.0f),
                cameraUp);
        this->vpMatrix = this->pMatrix * this->vMatrix;
        this->vpMatrixInverse = glm::inverse(this->pMatrix * this->vMatrix);
        this->vMatrixInverse = glm::inverse(this->vMatrix);
        this->pMatrixInverse = glm::inverse(this->pMatrix);
    }
}