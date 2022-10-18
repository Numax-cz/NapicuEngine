#pragma once

#ifndef OPENGL_SPRITERENDER_H
#define OPENGL_SPRITERENDER_H

#include "../Object/Component.h"
#include "../Utils/Console.h"
#include "../Render/Texture.h"
#include "Sprite.h"


namespace Napicu {
    class SpriteRender : public Napicu::Component {

    protected:
        glm::vec4 *color = nullptr;
        Napicu::Sprite* sprite = nullptr;

    public:
        SpriteRender() {

        }

        SpriteRender(glm::vec4 *color) : color(color) {

        }

        SpriteRender(Napicu::Sprite* sprite) : sprite(sprite), color(new glm::vec4(0, 1, 1, 1)){

        }

        void start() override {
        }

        void update(double delta_time) override {
        }

        glm::vec4 *getColor() const { return this->color; }

        Napicu::Texture *getTexture() const {
            return this->sprite->getTexture();
        }

        const std::vector<glm::vec2> getTexCords() const {
            return this->sprite->getTexCords();
        }
    };
}


#endif //OPENGL_SPRITERENDER_H