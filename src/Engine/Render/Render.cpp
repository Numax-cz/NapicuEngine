

#include "Render.h"
namespace Napicu{
    Render::Render(): batches(*new std::list<Napicu::Batch*>()) {


    }

    void Render::add(Napicu::SpriteRender *sprite) {
        bool add = false;
        for(Napicu::Batch* batch : this->batches){
            if(batch->hasRoom()){
                batch->addSprite(sprite);
                add = true;
                break;
            }
        }

        if(!add){
            Napicu::Batch* bt = new Napicu::Batch(this->BATCH_SIZE);

            bt->start();
            this->batches.push_back(bt);
            bt->addSprite(sprite);
        }
    }

    void Render::add(Napicu::Object *object) {
        Napicu::SpriteRender* sp = object->getComponent(*new Napicu::SpriteRender);
        if(sp){
            this->add(sp);
        }
    }

    void Render::render() {
        for(Napicu::Batch* batch : this->batches){
            batch->render();
        }
    }


}