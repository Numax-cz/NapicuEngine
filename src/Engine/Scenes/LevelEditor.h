#pragma once

#include "../Scene.h"
#include <iostream>
#include "../Components/MouseEventControls.h"

namespace Napicu {

    class LevelEditor : public Napicu::Scene {

    private:
        std::list<Napicu::Sprite *> explorerObjectsList = {};
        float angle = 0;
        void loadAssets();


    public:
        LevelEditor() : Napicu::Scene() {

        };

        //Napicu::MouseEventControls mouseControls = *new Napicu::MouseEventControls();
        Napicu::Object levelEditor = *new Napicu::Object("LevelEditor");

        void update(double delta_time) override;

        void render() override;

        void imGui() override;

        void init() override;

    };
}

