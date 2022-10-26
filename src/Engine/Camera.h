#pragma once


#include "glm/gtx/vector_angle.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace Napicu {
    class Camera {
    private:
        //projection - view
        glm::mat4 pMatrix;
        glm::mat4 vMatrix;
        glm::vec3 position;
        float rotation;



    public:
        Camera(float left, float right, float bottom, float top);
        void recalculateVMatrix();

        void setPosition(const glm::vec3 &position) {
            this->position = position;
            this->recalculateVMatrix();
        }

        void setRotation(float angle) {
            this->rotation = rotation;
            this->recalculateVMatrix();
        }

        const glm::mat4 &getProjectionMatrix() const { return this->pMatrix; }

        const glm::mat4 &getViewMatrix() const { return this->vMatrix; }

        const glm::mat4 getViewProjectionMatrix() const { return this->vMatrix * this->pMatrix; }

        const float getRotation() const { return this->rotation; }

        const glm::vec3 getPosition() const { return this->position; }

    };
}


