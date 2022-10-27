#include "Camera.h"
#include <iostream>

namespace Napicu {
    Camera::Camera(float left, float right, float bottom, float top)
            : pMatrix(glm::ortho(left, right, bottom, top, 0.0f, 100.0f)), vMatrix(1.0f) {

    }

    glm::mat4 Camera::getViewMatrix() {
        glm::vec3 front = * new glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = * new glm::vec3(0.0f, 1.0f, 0.0f);

        //this->vMatrix = * new glm::mat4(1.0f);

        this->vMatrix = glm::lookAt(position, position + front, up);



        return this->vMatrix;
    }

    glm::mat4 Camera::getProjectionMatrix() {
        return this->pMatrix;
    }

    glm::mat4 Camera::getViewProjectionMatrix() {
        return this->getViewMatrix() * this->getProjectionMatrix();
    }


}