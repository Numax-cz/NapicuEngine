#include "Camera.h"
#include <iostream>

namespace Napicu {
    Camera::Camera(float left, float right, float bottom, float top)
            : pMatrix(glm::ortho(left, right, bottom, top, 0.0f, 100.0f)), vMatrix(1.0f) {
        this->recalculateVMatrix();
    }

    void Camera::recalculateVMatrix() {
        glm::vec3 cameraFront = *new glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cameraUp = *new glm::vec3(0.0f, 1.0f, 0.0f);
        this->vMatrix = {};

        this->vMatrix = glm::lookAt(

                *new glm::vec3(position.x, position.y, 20.0f),
                cameraFront + *new glm::vec3(position.x, position.y, 0.0f),
                cameraUp);

        this->vpMatrix = pMatrix * vMatrix;
        this->vpMatrixInverse = glm::inverse(pMatrix * vMatrix);
    }
}