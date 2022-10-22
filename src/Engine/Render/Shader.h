#pragma once


#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vector>
#include <string>


namespace Napicu {

    class Shader {

    private:
        unsigned int programId;

    public:
        std::string vertex;
        std::string fragment;

        explicit Shader(std::string file_path);

        void compile();

        void use();

        void detach();

        void uploadUniformMat4(std::string name, const glm::mat4 &matrix);

        void uploadUniformMVec4(std::string name, const glm::vec4 &vec);

        void uploadUniformFloat(std::string name, float val);

        void uploadUniformInt(std::string name, int val);

        void uploadTexture(std::string name, std::vector<int> arraySlot);

        void uploadTexture(std::string name);
    };
}


