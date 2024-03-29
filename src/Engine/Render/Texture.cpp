#include "Texture.h"
#include "../Utils/Console.h"
#include "stb_image.h"
#include "glad/glad.h"

namespace Napicu {
    Texture::Texture(const std::string &path)
            : file_path(path), width(0), height(0), buffer(nullptr), bpp(0), render_id(0) {

        stbi_set_flip_vertically_on_load(1);
        this->buffer = stbi_load(path.c_str(), &this->width, &this->height, &bpp, 4);

        if (!this->buffer)
            Napicu::Console::Log("(Texture) Could not load image " + path);


        glGenTextures(1, &this->render_id);
        glBindTexture(GL_TEXTURE_2D, this->render_id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, this->buffer);

        this->Unbind();

        if (this->buffer) stbi_image_free(this->buffer);
    }

    Texture::Texture() : render_id(-1), width(-1), height(-1) { }

    Texture::Texture(int width, int height) : width(width), height(height), file_path("GeneratedTexture") {
        glGenTextures(1, &this->render_id);
        glBindTexture(GL_TEXTURE_2D, this->render_id);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    }


    Texture::~Texture() {
        glDeleteTextures(1, &this->render_id);
    }

    void Texture::Bind(int index) const {
        glActiveTexture(GL_TEXTURE0 + index);
        glBindTexture(GL_TEXTURE_2D, this->render_id);
    }

    void Texture::Unbind() const {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}