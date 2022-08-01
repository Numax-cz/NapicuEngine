

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include "../Utils/Console.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>



namespace Napicu{

    class Shader {

    private:
        unsigned int programId;

    public:
        const char* vertex;
        const char* fragment;
        explicit Shader(const std::string& file_path);
        void compile();
        void use();
        void detach();

    };
}


#endif //OPENGL_SHADER_H
