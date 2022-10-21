

#include "LevelEditor.h"

#include "Components/SpriteRender.h"

namespace Napicu {

    void LevelEditor::init() {





        Napicu::Object *ob = new Napicu::Object("Obj", *new Napicu::ObjectTransform(*new glm::vec2(400, 100),
                                                                                    *new glm::vec2(500, 500), 2));
        ob->addComponent(new Napicu::SpriteRender(
                new Napicu::Sprite(new Napicu::Texture("src/assets/blendImage1.png"))));

        this->addObjectToScene(ob);



        Napicu::Object *ob1 = new Napicu::Object("Obj2", *new Napicu::ObjectTransform(*new glm::vec2(800, 100),
                                                                                      *new glm::vec2(500, 500), 4));


        ob1->addComponent(new Napicu::SpriteRender(
                new Napicu::Sprite(new Napicu::Texture("src/assets/blendImage2.png"))));

        this->addObjectToScene(ob1);



    }

    void LevelEditor::update(double delta_time) {
        for (Napicu::Object *object: this->sceneObjects) {
            object->update(delta_time);
        }


        this->render->render();
    }
}
