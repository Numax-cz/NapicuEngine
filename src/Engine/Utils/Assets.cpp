#include "Assets.h"

namespace Napicu{

    Napicu::Shader* Assets::getShader(const std::string& src) {
        auto searchElement = Assets::shaders.find(src);
        if(searchElement != Assets::shaders.end()) return searchElement->second;
        else {
            Napicu::Shader *shader = new Napicu::Shader(src);
            shader->compile();
            Assets::shaders.insert({src, shader});
            return shader;
        }
    }

    Napicu::Texture* Assets::getTexture(const std::string& src) {
        auto searchElement = Assets::textures.find(src);
        if(searchElement != Assets::textures.end()) return searchElement->second;
        else {
            Napicu::Texture *texture = new Napicu::Texture(src);
            Assets::textures.insert({src, texture});
            return texture;
        }
    }
}

