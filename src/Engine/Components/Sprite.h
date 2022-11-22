

#ifndef OPENGL_SPRITE_H
#define OPENGL_SPRITE_H

#include "../Render/Texture.h"
#include "../Object/Object.h"
#include <glm/vec2.hpp>
#include <iostream>
#include <vector>

namespace Napicu {
    class Sprite {

    protected:
        Napicu::Texture texture;
        std::vector<glm::vec2> texCords;


    public:
        Sprite(const Napicu::Texture& texture);

        Sprite(const Napicu::Texture& texture, std::vector<glm::vec2> texCords);

        static Napicu::Object *generateSpriteObject(Sprite *sprite, float sizeX, float sizeY);

        std::vector<glm::vec2> getTexCords() const { return this->texCords; }

        Napicu::Texture &getTexture() { return this->texture; }

        void setTexture(const Napicu::Texture& texture);

    };

}

#endif //OPENGL_SPRITE_H
