

#include "Camera.h"

namespace Napicu{


    Camera::Camera(float left, float right, float bottom, float top)
        : pMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)){

    }

    void Camera::RecalculateVMatrix() {
        glm::mat4 tr = glm::translate(glm::mat4(1.0f), this->position)
                * glm::rotate(glm::mat4(1.0f), this->rotation, glm::vec3(0,0,1));

        this->vMatrix = glm::inverse(tr);
        //this->viewPMatrix = this->pMatrix * this->vMatrix;
    }


}