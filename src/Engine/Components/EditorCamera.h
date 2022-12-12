#pragma once
#include "Component.h"
#include <glm/vec2.hpp>
#include "../Camera.h"

namespace Napicu{
    class EditorCamera : public Napicu::Component{
    private:
        Napicu::Camera* editorCamera;
        glm::vec2  originPosition;

        float lerpTime = 0.0f;
        float dragDebounce = 0.032f;

    public:
        EditorCamera(Napicu::Camera* camera);

        void update(double delta_time) override;

    };
}


