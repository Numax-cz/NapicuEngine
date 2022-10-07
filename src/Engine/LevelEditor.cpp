

#include "LevelEditor.h"

#include "Components/SpriteRender.h"

namespace Napicu {

    void LevelEditor::init() {
        Napicu::Object* object = new Napicu::Object("TestObject");
        object->addComponent(*new Napicu::SpriteRender());
        this->addObjectToScene(*object);
    }

    void LevelEditor::update(double delta_time) {
        for (Napicu::Object& object : this->sceneObjects){
            object.update(delta_time);
        }

        this->render->render();
    }
}
