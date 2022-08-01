

#include "Camera.h"
namespace Napicu{

    Camera::Camera(Vector2f position) {
        this->position = position;
        this->pMatrix = *new Matrix4f();
        this->vMatrix = *new Matrix4f();
    }

    void Camera::pAdjust() {
        this->pMatrix.Identity();
        this->pMatrix.Orthographic(0.0f, 32.0f * 40.0f, 0.0f, 32.0f * 21.0f, 0.0f, 100.0f);
    }

    Matrix4f Camera::getVMatrix() {
        this->vMatrix = Matrix4f::Translate(this->position);

    }
}