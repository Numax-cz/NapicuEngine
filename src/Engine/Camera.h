#pragma once


#include "glm/gtx/vector_angle.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace Napicu {
    class Camera {
    private:
        //projection - view
        glm::mat4 pMatrix, vMatrix, vpMatrix, vpMatrixInverse = {};
        glm::vec3 position = {-200, 0, 0};
        float rotation = 0.0f;


    public:
        Camera(float left, float right, float bottom, float top);

        void recalculateVMatrix();

        void setPosition(const glm::vec3 &position) {
            this->position = position;
            this->recalculateVMatrix();
        }

        void setRotation(float angle) {
            this->rotation = angle;
            this->recalculateVMatrix();
        }

        const glm::mat4 getProjectionMatrix() const { return this->pMatrix; }

        const glm::mat4 getViewMatrix() const { return this->vMatrix; }

        const glm::mat4 getViewProjectionMatrix() const { return this->vpMatrix; }

        const glm::mat4 getViewProjectionMatrixInverse() const { return this->vpMatrixInverse; }

        const float getRotation() const { return this->rotation; }

        const glm::vec3 getPosition() const { return this->position; }

    };
}


