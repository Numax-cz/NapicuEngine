

#ifndef OPENGL_LEVELSCENE_H
#define OPENGL_LEVELSCENE_H
#include "Scene.h"
#include "Render/Shader.h"


namespace Napicu{
    class Level : public Napicu::Scene{
    public:
        Level() : Napicu::Scene(){


        }
        void update(double delta_time) override;
        void init() override;
    };
}


#endif //OPENGL_LEVELSCENE_H
