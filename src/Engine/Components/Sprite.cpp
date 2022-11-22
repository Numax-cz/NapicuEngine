

#include "Sprite.h"
#include "SpriteRender.h"

namespace Napicu {

    Sprite::Sprite(const Napicu::Texture& texture) : texture(texture) {
        this->texCords = std::vector<glm::vec2>{
                glm::vec2(1, 1),
                glm::vec2(1, 0),
                glm::vec2(0, 0),
                glm::vec2(0, 1),
        };
    }

    Sprite::Sprite(const Napicu::Texture& texture, std::vector<glm::vec2> texCords) : texture(texture), texCords(texCords) {

    }

    Napicu::Object *Sprite::generateSpriteObject(Sprite *sprite, float sizeX, float sizeY) {
        Napicu::SpriteRender *render = new Napicu::SpriteRender();
        Napicu::ObjectTransform objectTransform = Napicu::ObjectTransform(*new glm::vec2(),
                                                                               *new glm::vec2(sizeX, sizeY), 0);
        Napicu::Object *object = new Napicu::Object("NewObject", objectTransform);
        render->setSprite(sprite);
        object->addComponent(render);

        return object;
    }

    void Sprite::setTexture(const Napicu::Texture& texture) {
        this->texture = texture;
    }
}