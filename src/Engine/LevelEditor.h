

#ifndef OPENGL_LEVELEDITOR_H
#define OPENGL_LEVELEDITOR_H

#include "Utils/Console.h"
#include "Scene.h"


namespace Napicu{

    class LevelEditor : public Napicu::Scene{


    public:
        LevelEditor() : Napicu::Scene() {};

        void update(double delta_time) override;

    };
}


#endif //OPENGL_LEVELEDITOR_H
