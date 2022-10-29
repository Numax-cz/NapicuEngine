#pragma once

#include "../Scene.h"
#include <iostream>

namespace Napicu {

    class LevelEditor : public Napicu::Scene {

    private:
        std::list<Napicu::Sprite*> explorerObjectsList = {};


    public:
        LevelEditor() : Napicu::Scene() {

        };

        void update(double delta_time) override;

        void imGui() override;

        void init() override;

    };
}

