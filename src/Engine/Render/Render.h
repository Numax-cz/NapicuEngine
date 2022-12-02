#pragma once


#include <iostream>
#include "Batch.h"
#include <list>

namespace Napicu {

    class Render {
    protected:
        std::list<Napicu::Batch *> batches = {};
        static Napicu::Shader activeShader;

    private:
        const int BATCH_SIZE = 1000;


    public:
        Render();

        void add(Napicu::SpriteRender *sprite);

        void add(Napicu::Object *object);

        void render();

        static void bindShader(const Napicu::Shader& shader);

        static Napicu::Shader& getActiveShader();

        static bool comp(Napicu::Batch *a, Napicu::Batch *b);
    };

}



