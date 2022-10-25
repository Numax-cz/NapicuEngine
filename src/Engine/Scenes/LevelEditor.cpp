

#include "LevelEditor.h"
#include "../Components/Rigid.h"

namespace Napicu {

    void LevelEditor::init() {

//        if(levelLoad){
//
//            return;
//        }


        Napicu::Object *ob = new Napicu::Object("Obj", new Napicu::ObjectTransform(*new glm::vec2(400, 100),
                                                                                   *new glm::vec2(500, 500), 1));
        ob->addComponent(new Napicu::SpriteRender());
        ob->addComponent(new Napicu::Rigid());

        this->addObjectToScene(ob);
        this->activeGameObject = ob;


    }

    void LevelEditor::update(double delta_time) {
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





        if(ImGui::ImageButton(reinterpret_cast<ImTextureID>(this->flappyBirdImage.getTexture()->getTextureID()),
                              ImVec2(50, 50),
                              ImVec2(this->flappyBirdImage.getTexCords()[0].x, this->flappyBirdImage.getTexCords()[0].y),
                            ImVec2(this->flappyBirdImage.getTexCords()[2].x, this->flappyBirdImage.getTexCords()[2].y),
                            0)){

            //TODO CLICK

        }

        ImGui::End();
    }


}
