

#include "Matrix4f.h"
#include "Vector2f.h"
#include <cmath>

namespace Napicu{
    Matrix4f Matrix4f::Identity() {
        Matrix4f* mat = new Matrix4f();

        for (int i = 0; i < 16; i++) {
            mat->elements[i] = 0.0f;
        }
        mat->elements[0 + 0 * 4] = 1.0f;
        mat->elements[1 + 1 * 4] = 1.0f;
        mat->elements[2 + 2 * 4] = 1.0f;
        mat->elements[3 + 3 * 4] = 1.0f;

        return *mat;
    }

    Matrix4f Matrix4f::Translate(Vector2f vector2F) {
        Matrix4f mat = Identity();

        mat.elements[0 + 3 * 4] = vector2F.x;
        mat.elements[1 + 3 * 4] = vector2F.y;

        return mat;
    }

    Matrix4f Matrix4f::Rotate(float angle) {
        Matrix4f mat = Identity();
        float r = (float) ((angle * M_PI)/180.0f);
        float c = (float) cos(r);
        float s = (float) sin(r);

        mat.elements[0 + 0 * 4] = c;
        mat.elements[1 + 0 * 4] = s;

        mat.elements[0 + 1 * 4] = -s;
        mat.elements[1 + 1 * 4] = c;

        return mat;
    }

    Matrix4f Matrix4f::Orthographic(float left, float right, float bottom, float top, float near, float far) {
        Matrix4f mat = Identity();

        mat.elements[0 + 0 * 4] = 2.0f / (right - left);

        mat.elements[1 + 1 * 4] = 2.0f / (top - bottom);

        mat.elements[2 + 2 * 4] = 2.0f / (near - far);

        mat.elements[0 + 3 * 4] = (left + right) / (left - right);
        mat.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
        mat.elements[2 + 3 * 4] = (far + near) / (far - near);

        return mat;
    }

    Matrix4f Matrix4f::And(Matrix4f matrix4F) {
        Matrix4f* mat = new Matrix4f();
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                float sum = 0.0f;
                for (int e = 0; e < 4; e++) {
                    sum += this->elements[x + e * 4] * matrix4F.elements[e + y * 4];
                }
                mat->elements[x + y * 4] = sum;
            }
        }
        return *mat;
    }
}