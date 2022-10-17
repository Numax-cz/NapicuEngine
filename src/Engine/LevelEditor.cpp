

#include "LevelEditor.h"

#include "Components/SpriteRender.h"

namespace Napicu {

    void LevelEditor::init() {


        Napicu::Object *ob = new Napicu::Object("Obj", *new Napicu::ObjectTransform(*new glm::vec2(800, 100),
                                                                                    *new glm::vec2(500, 500)));
        ob->addComponent(new Napicu::SpriteRender(new Napicu::Texture("src/assets/bird.png")));
        this->addObjectToScene(ob);

    }

    void LevelEditor::update(double delta_time) {
        for (Napicu::Object *object: this->sceneObjects) {
            object->update(delta_time);
        }


        this->render->render();
    }
}
