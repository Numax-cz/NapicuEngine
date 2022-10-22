

#include "LevelEditor.h"

#include "Components/SpriteRender.h"

namespace Napicu {

    void LevelEditor::init() {





        Napicu::Object *ob = new Napicu::Object("Obj", *new Napicu::ObjectTransform(*new glm::vec2(400, 100),
                                                                                    *new glm::vec2(500, 500), 1));
        ob->addComponent(new Napicu::SpriteRender(
                new Napicu::Sprite(new Napicu::Texture("src/assets/bird.png"))));

        this->addObjectToScene(ob);






    }

    void LevelEditor::update(double delta_time) {
        for (Napicu::Object *object: this->sceneObjects) {
            object->update(delta_time);
        }


        this->render->render();
    }
}
