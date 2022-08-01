

#ifndef OPENGL_LEVELEDITOR_H
#define OPENGL_LEVELEDITOR_H

#include "Utils/Console.h"
#include "Scene.h"
#include "Render/Shader.h"


namespace Napicu{

    class LevelEditor : public Napicu::Scene{


    public:
        LevelEditor() : Napicu::Scene() {
            Shader* test = new Shader("src/Engine/shaders/default.glsl");

        };

        void update(double delta_time) override;

    };
}


#endif //OPENGL_LEVELEDITOR_H
