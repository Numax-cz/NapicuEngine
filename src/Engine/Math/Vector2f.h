#ifndef OPENGL_VECTOR2F_H
#define OPENGL_VECTOR2F_H

namespace Napicu{
    struct Vector2f {
        float x;
        float y;

        Vector2f(float x, float y) : x(x), y(y) {};
        Vector2f() : x(0.0f), y(0.0f) {};
    };
}

#endif //OPENGL_VECTOR2F_H
