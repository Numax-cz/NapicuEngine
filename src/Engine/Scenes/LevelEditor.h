#pragma once

#include "../Scene.h"


namespace Napicu {

    class LevelEditor : public Napicu::Scene {

    private:
        Napicu::Sprite flappyBirdImage = *new Napicu::Sprite(new Napicu::Texture("src/assets/bird.png"));


    public:
        LevelEditor() : Napicu::Scene() {

        };

        void update(double delta_time) override;

        void imGui() override;

        void init() override;

    };
}

