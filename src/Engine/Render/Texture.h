#pragma once


#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Napicu {
    class Texture {
    private:
        unsigned int render_id;
        std::string file_path;
        unsigned char *buffer;
        int width, height, bpp;

    public:
        Texture(const std::string &path);

        ~Texture();

        void Bind(int index) const;

        void Unbind() const;

        inline int GetWidth() const { return this->width; }

        inline int GetHeight() const { return this->height; }


    };
}


