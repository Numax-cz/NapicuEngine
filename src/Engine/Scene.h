

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

#include "Camera.h"
namespace Napicu{

    class Scene {
    public:
        Scene() {};
        virtual void update(double delta_time) {};
        virtual void init() {};
        Napicu::Camera camera = *new Napicu::Camera(-1.0f, 1.0f, -1.0f, 1.0f);

    };


}


#endif //OPENGL_SCENE_H
