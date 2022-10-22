#pragma once


#include "Scene.h"


namespace Napicu {

    class LevelEditor : public Napicu::Scene {

    private:


    public:
        LevelEditor() : Napicu::Scene() {

        };

        void update(double delta_time) override;
        void imGui() override;

        void init() override;

    };
}

