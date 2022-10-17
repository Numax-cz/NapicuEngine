#pragma once


#include "../Utils/Console.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


namespace Napicu {

    class Shader {

    private:
        unsigned int programId;

    public:
        std::string vertex;
        std::string fragment;

        explicit Shader(const std::string &file_path);

        void compile();

        void use();

        void detach();

        void uploadUniformMat4(const std::string &name, const glm::mat4 &matrix);

        void uploadUniformMVec4(const std::string &name, const glm::vec4 &vec);

        void uploadUniformFloat(const std::string &name, float val);

        void uploadUniformInt(const std::string &name, int val);

        void uploadTexture(const std::string &name, std::vector<int> arraySlot);

        void uploadTexture(const std::string &name);
    };
}


