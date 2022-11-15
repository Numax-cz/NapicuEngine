#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "Component.h"

namespace Napicu {

    class Rigid : public Napicu::Component {
    private:
        glm::vec2 *velocity = new glm::vec2(0, 0.5f);
        glm::vec4 *tmp = new glm::vec4(0, 0, 0, 0);


        nlohmann::json toJson() override{
            nlohmann::json  i;
            i["velocity"]["x"] = this->velocity->x;
            i["velocity"]["y"] = this->velocity->x;

            return i;
        }
    };
}