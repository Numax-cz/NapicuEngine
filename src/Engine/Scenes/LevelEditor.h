#pragma once

#include "../Scene.h"
#include <iostream>
#include "../Components/MouseEventControls.h"

namespace Napicu {

    class LevelEditor : public Napicu::Scene {

    private:
        std::list<Napicu::Sprite *> explorerObjectsList = {};


    public:
        LevelEditor() : Napicu::Scene() {

        };

        Napicu::MouseEventControls mouseControls = *new Napicu::MouseEventControls();

        void update(double delta_time) override;

        void imGui() override;

        void init() override;

    };
}

