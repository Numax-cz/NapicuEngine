#pragma once
#include "../../Scene.h"
#include "../../Object/Object.h"
#include "../../Render/Select.h"

namespace Napicu{
    class Inspector {
    private:
        Napicu::Object *activeGameObject = nullptr;
        Napicu::Select *selectedTexture = nullptr;


    public:
        void imgui();

        Inspector(Napicu::Select* selectedTexture);

        void update(float delta_time, Napicu::Scene* scene);
    };
}

