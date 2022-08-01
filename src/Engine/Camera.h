

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "Math/Vector2f.h"
#include "Math/Matrix4f.h"

namespace Napicu{
    class Camera {
    private:
        //projection - view
        Matrix4f pMatrix;
        Matrix4f vMatrix;
        Vector2f position;

    public:
        Camera(Vector2f position);
        Matrix4f getVMatrix();
        void pAdjust();

    };

}


#endif //OPENGL_CAMERA_H
