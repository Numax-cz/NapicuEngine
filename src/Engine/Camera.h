#pragma once


#include "glm/gtx/vector_angle.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace Napicu {
    class Camera {
    private:
        //projection - view
        glm::mat4 pMatrix, vMatrix;
        glm::vec3 position = *new glm::vec3(0.0f, 0.0f, 0.0f);

       // float rotation;



    public:
        Camera(float left, float right, float bottom, float top);

        glm::mat4 getViewMatrix();

        glm::mat4 getProjectionMatrix();

        glm::mat4 getViewProjectionMatrix();


    };
}


