#pragma once


#include <iostream>
#include "Batch.h"
#include <list>

namespace Napicu{

    class Render {
    protected:
        std::list<Napicu::Batch*> batches = *new std::list<Napicu::Batch*>();

    private:
        const int BATCH_SIZE = 100;


    public:
        Render();
        void add(Napicu::SpriteRender* sprite);
        void add(Napicu::Object* object);
        void render();
    };

}



