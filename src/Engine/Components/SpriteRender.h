#pragma once


#include "../Components/Component.h"
#include "../Utils/Console.h"
#include "../Render/Texture.h"
#include "Sprite.h"
#include <imgui.h>
#include <glm/vec4.hpp>

namespace Napicu {
    class SpriteRender : public Napicu::Component {

    protected:
        glm::vec4 color = glm::vec4(0, 1, 1, 1);
        Napicu::Sprite *sprite = nullptr;
        Napicu::ObjectTransform lastTransform;
        bool dirty = true;

    public:
        SpriteRender() {

        }

        SpriteRender(glm::vec4 color) : color(color) {

        }

        SpriteRender(Napicu::Sprite* sprite) : sprite(sprite), lastTransform(this->object->transform) {

        }

        void start() override {
            this->lastTransform = this->object->transform.copy();
        }

        void update(double delta_time) override {
            if (!this->lastTransform.equals(this->object->transform)) {
                this->object->transform.copy(this->lastTransform);
                this->dirty = true;
            }
        }

        void imGui() override {
            float colors[4] = {this->color.x, this->color.y, this->color.z, this->color.w};
            if (ImGui::ColorPicker4("Pico picker vole: ", (float *) &colors)) { //TODO
                this->setColor(glm::vec4(colors[0], colors[1], colors[2], colors[3]));
            }
        }

        nlohmann::json toJson() override{
            nlohmann::json i;
            i["name"] = "SpriteRender";
            i["color"]["x"] = this->color.x;
            i["color"]["y"] = this->color.y;
            i["color"]["z"] = this->color.z;
            i["color"]["w"] = this->color.w;

            if(this->sprite){
                for (glm::vec2 vector : this->sprite->getTexCords()) {
                    i["sprite"]["texCoords"]["x"] = vector.x;
                    i["sprite"]["texCoords"]["y"] = vector.y;
                }

                i["sprite"]["texture"]["width"] = this->sprite->getTexture().GetWidth();
                i["sprite"]["texture"]["height"] = this->sprite->getTexture().GetHeight();
                i["sprite"]["texture"]["path"] = this->sprite->getTexture().getPath();
                i["sprite"]["texture"]["textureID"] = this->sprite->getTexture().getTextureID();
            }


            return i;
        }



        glm::vec4 getColor() const { return this->color; }

        const bool isDirty() const { return this->dirty; }

        void resetDirty() { this->dirty = false; }

        Napicu::Texture &getTexture() const {
            return this->sprite->getTexture();
        }

        const std::vector<glm::vec2> getTexCords() const {
            return this->sprite->getTexCords();
        }

        void setSprite(Napicu::Sprite *sprite) {
            this->sprite = sprite;
            this->dirty = true;
        }

        bool isSprite(){
            return (this->sprite != nullptr);
        }

        void setColor(glm::vec4 color) {
            this->color = color;
            this->dirty = true;
        }

        void setTexture(const Napicu::Texture& texture){
            this->sprite->setTexture(texture);
        }
    };
}
