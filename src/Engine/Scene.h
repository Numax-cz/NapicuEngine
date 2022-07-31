

#ifndef OPENGL_SCENE_H
#define OPENGL_SCENE_H

namespace Napicu{

    class Scene {
    public:
        Scene() {};
        virtual void update(double delta_time) {};
    };

}


#endif //OPENGL_SCENE_H
