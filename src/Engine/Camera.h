

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
        glm::vec3 position;
        float rotation;

        void RecalculateVMatrix();


    public:
        Camera(float left, float right, float bottom, float top);
        void setPosition(const glm::vec3& position) {this->position = position; this->RecalculateVMatrix();}
        void setRotation(float angle) {this->rotation = rotation; this->RecalculateVMatrix();}

        const glm::mat4& GetPMatrix() const {return this->pMatrix;}
        const glm::mat4& GetVMatrix() const {return this->vMatrix;}


    };
}


#endif //OPENGL_CAMERA_H
