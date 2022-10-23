

#include "Sprite.h"

namespace Napicu {

    Sprite::Sprite(Napicu::Texture *texture) : texture(texture) {
        this->texCords = *new std::vector<glm::vec2>{
                *new glm::vec2(1, 1),
                *new glm::vec2(1, 0),
                *new glm::vec2(0, 0),
                *new glm::vec2(0, 1),
        };
    }

    Sprite::Sprite(Napicu::Texture *texture, std::vector<glm::vec2> texCords) : texture(texture), texCords(texCords) {

    }
}