#pragma once

#ifndef OPENGL_SPRITERENDER_H
#define OPENGL_SPRITERENDER_H

#include "../Object/Component.h"
#include "../Utils/Console.h"
#include "../Render/Texture.h"

namespace Napicu {
    class SpriteRender : public Napicu::Component {

    protected:
        glm::vec4 *color = nullptr;
        glm::vec2 *texCords;
        Napicu::Texture *texture = nullptr;



    public:



        SpriteRender() {

        }

        SpriteRender(glm::vec4 *color) : color(color) {

        }

        SpriteRender(Napicu::Texture *texture) : texture(texture), color(new glm::vec4(0, 1, 1, 1)){


        }





        void start() override {
        }

        void update(double delta_time) override {
        }


        glm::vec4 *getColor() const { return this->color; }

        Napicu::Texture *getTexture() const {return this->texture;}

        const std::vector<glm::vec2> getTexCords() const {
            std::vector<glm::vec2> i = *new std::vector<glm::vec2>{
                    *new glm::vec2(1, 1),
                    *new glm::vec2(1, 0),
                    *new glm::vec2(0, 0),
                    *new glm::vec2(0,1),
            };
            return i;
        }


    };
}


#endif //OPENGL_SPRITERENDER_H