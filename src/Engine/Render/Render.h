#pragma once


#include <iostream>
#include <list>
#include "Batch.h"

namespace Napicu{
    class Batch;
    class SpriteRender;
    class Render {

    private:
        const int BATCH_SIZE = 100;
        std::list<Napicu::Batch*> batches;


    public:
        Render();
        void add(Napicu::SpriteRender* sprite);
        void add(Napicu::Object* object);
        void render();
    };

}

