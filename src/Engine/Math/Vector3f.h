#ifndef OPENGL_VECTOR3F_H
#define OPENGL_VECTOR3F_H

namespace Napicu{
    struct Vector3f {
        float x;
        float y;
        float z;

        Vector3f(float x, float y, float z) : x(x), y(y), z(z){};
        Vector3f() : x(0.0f), y(0.0f), z(0.0) {};
    };
}

#endif //OPENGL_VECTOR3F_H
