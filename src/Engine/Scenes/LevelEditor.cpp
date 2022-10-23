

#include "LevelEditor.h"

#include "../Components/SpriteRender.h"

namespace Napicu {

    void LevelEditor::init() {





        Napicu::Object *ob = new Napicu::Object("Obj", new Napicu::ObjectTransform(*new glm::vec2(400, 100),
                                                                                    *new glm::vec2(500, 500), 1));
        ob->addComponent(new Napicu::SpriteRender());

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

        ImGui::Begin("Test");
        ImGui::Text("Test text");
        ImGui::End();
    }


}
