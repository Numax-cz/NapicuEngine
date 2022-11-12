#pragma once
#include "Texture.h"

namespace Napicu{
    class Framebuffer{
    private:
        unsigned int fboID = 0;
        Napicu::Texture *texture = nullptr;

    public:
        Framebuffer(int widht, int height);

        void bind();

        void unbind();

        unsigned int getFboId() const;

        unsigned int getTextureID();
    };
}