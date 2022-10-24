#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>


namespace Napicu{

class Rigid : public Napicu::Component{
    private:
        glm::vec3 *velocity = new glm::vec3(0, 0.5, 0);
        glm::vec4 *tmp = new glm::vec4(0, 0, 0, 0);
        int colliderType = 0;
        float friction = 0.8f;


    };

}