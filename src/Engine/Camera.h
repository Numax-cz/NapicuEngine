#pragma once


#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H
#include "glm/gtx/vector_angle.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Render/Shader.h"


namespace Napicu{
    class Camera {
    private:
        //projection - view
        glm::mat4 pMatrix;
        glm::mat4 vMatrix;
        glm::mat4 vPMatrix;
        glm::vec3 position;
        float rotation;

        void recalculateVMatrix();


    public:
        Camera(float left, float right, float bottom, float top);
        void setPosition(const glm::vec3& position) {this->position = position;
            this->recalculateVMatrix();}
        void setRotation(float angle) {this->rotation = rotation;
            this->recalculateVMatrix();}

        const glm::mat4& getProjectionMatrix() const {return this->pMatrix;}
        const glm::mat4& getViewMatrix() const {return this->vMatrix;}
        const glm::mat4 getViewProjectionMatrix() const {return this->vPMatrix;}

        const float getRotation() const {return this->rotation;}
        const glm::vec3 getPosition() const {return this->position;}

    };
}


#endif //OPENGL_CAMERA_H
