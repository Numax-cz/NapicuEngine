#include "LevelEditor.h"
#include "../Components/Rigid.h"
#include "../Events/MouseEvent.h"
#include "../Components/Grid.h"
#include <nlohmann/json.hpp>
#include <nlohmann/adl_serializer.hpp>
#include "../Utils/Json.h"

namespace Napicu {

    void LevelEditor::init() {

//        if(levelLoad){
//
//            return;
//        }
        levelEditor.addComponent(new Napicu::MouseEventControls());
        levelEditor.addComponent(new Napicu::Grid());

        this->explorerObjectsList = {new Napicu::Sprite(new Napicu::Texture("src/assets/bird.png"))};

        Napicu::Object *ob = new Napicu::Object("Obj", new Napicu::ObjectTransform(*new glm::vec2(400, 100),
                                                                                   *new glm::vec2(500, 500), 1));

        ob->addComponent(new Napicu::SpriteRender());
        //ob->addComponent(new Napicu::Rigid());

        this->addObjectToScene(ob);
        this->activeGameObject = ob;
    }

    void LevelEditor::update(double delta_time) {
        this->levelEditor.update(delta_time);
        for (Napicu::Object *object: this->sceneObjects) {
            object->update(delta_time);
        }

        this->render->render();
    }

    void LevelEditor::imGui() {
        ImGui::Begin("Explorer");

        ImVec2 windowPosition = ImGui::GetWindowPos();
        ImVec2 windowScale = ImGui::GetWindowSize();

        float windowXY = windowPosition.x + windowPosition.y;

        for (Napicu::Sprite *sprite: this->explorerObjectsList) {

            if (ImGui::ImageButton(reinterpret_cast<ImTextureID>(sprite->getTexture()->getTextureID()),
                                   ImVec2(50, 50),
                                   ImVec2(sprite->getTexCords()[0].x,
                                          sprite->getTexCords()[0].y),
                                   ImVec2(sprite->getTexCords()[2].x,
                                          sprite->getTexCords()[2].y),
                                   0)) {
                Napicu::Object *ob = Napicu::Sprite::generateSpriteObject(sprite, 32, 32);

                this->levelEditor.getComponent(new Napicu::MouseEventControls)->pickUpObject(ob);
            }
        }

        ImGui::End();
    }


}
