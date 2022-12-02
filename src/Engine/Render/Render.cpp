#include "../Object/Object.h"

#include "Render.h"


namespace Napicu {
    Render::Render() {


    }

    void Render::add(Napicu::SpriteRender *sprite) {
        bool add = false;
        for (Napicu::Batch *const batch: this->batches) {
            if (batch->hasRoom() && batch->getZIndex() == sprite->object->transform.getZIndex()) {
                batch->addSprite(sprite);
                //batch->start(); // TODO
                add = true;
                break;
            }
        }


        if (!add) {
            Napicu::Batch *bt = new Napicu::Batch(this->BATCH_SIZE, sprite->object->transform.getZIndex());

            this->batches.push_back(bt);
            bt->addSprite(sprite);
            bt->start();
            this->batches.sort(this->comp);
        }
    }

    void Render::add(Napicu::Object *object) {
        Napicu::SpriteRender *sp = object->getComponent(new Napicu::SpriteRender);
        if (sp) {
            this->add(sp);
        }
    }

    void Render::render() {
        Render::activeShader.use();
        for (Napicu::Batch *batch: this->batches) {
            batch->render();
        }
    }

    bool Render::comp(Napicu::Batch *a, Napicu::Batch *b) {
        return (a->getZIndex() < b->getZIndex());
    }

    void Render::bindShader(const Shader &shader) {
        Render::activeShader = shader;
    }

    Napicu::Shader &Render::getActiveShader() {
        return Render::activeShader;
    }


}