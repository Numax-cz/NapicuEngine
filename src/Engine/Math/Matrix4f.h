#ifndef OPENGL_MATRIX4F_H
#define OPENGL_MATRIX4F_H

#include "Vector2f.h"

namespace Napicu{
    class Matrix4f {
    public:
        float elements[16] = {};

        static Matrix4f Identity();
        static Matrix4f Translate(Vector2f vector2F);
        static Matrix4f Rotate(float angle);
        static Matrix4f Orthographic(float left, float right, float bottom, float top, float near, float far);
        Matrix4f And(Matrix4f matrix4F);
    };
}

#endif //OPENGL_MATRIX4F_H
