#pragma once
#include <map>
#include <iostream>
#include "../Render/Shader.h"
#include "../Render/Texture.h"

namespace Napicu{
 class Assets{

 private:
     inline static std::map<std::string, Napicu::Shader*> shaders;

     inline static std::map<std::string, Napicu::Texture*> textures;

 public:
     static Napicu::Shader* getShader(const std::string& src);

     static Napicu::Texture* getTexture(const std::string& src);

 };
}




