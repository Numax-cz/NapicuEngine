

#include "Shader.h"

namespace Napicu {



    Shader::Shader(const std::string &file_path) {
        std::ifstream stream(file_path);


        if(stream.fail()){
            Napicu::Console::Log("Shader " + file_path  + " does not exist");
        }


        enum class ShaderType{
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };



        std::string line;
        std::stringstream ss[2];
        ShaderType shader_type = ShaderType::NONE;

        while(std::getline(stream, line)){
            if (line.find("#shader") != std::string::npos) {
                if (line.find("vertex") != std::string::npos)
                    shader_type = ShaderType::VERTEX;
                else if (line.find("fragment") != std::string::npos)
                    shader_type = ShaderType::FRAGMENT;
            } else ss[(int)shader_type] << line << "\n";
        }

        this->vertex = ss[0].str().c_str();
        this->fragment = ss[1].str().c_str();
    }


    void Shader::compile() {
        int vertexID, fragmentID;
        GLint success = 0;
        //Compile Vertex
        vertexID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexID, 1, &this->vertex, nullptr);
        glCompileShader(vertexID);

        glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
        if(success == GL_FALSE) Napicu::Console::Error("Vertex shader compilation failed");

        //Compile Fragment
        fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentID, 1, &this->fragment, nullptr);
        glCompileShader(fragmentID);

        glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
        if(success == GL_FALSE) Napicu::Console::Error("Fragment shader compilation failed");


        //Linking Vertex & Fragment
        this->programId = glCreateProgram();
        glAttachShader(this->programId, vertexID);
        glAttachShader(this->programId, fragmentID);
        glLinkProgram(this->programId);

        GLint is_link = GL_FALSE;
        glGetProgramiv(this->programId, GL_LINK_STATUS, &is_link);
        if(is_link == GL_FALSE) Napicu::Console::Error("Failed to linking shader");
    }

    void Shader::use() {

        glUseProgram(this->programId);
    }

    void Shader::detach() {
        glUseProgram(0);
   }

    void Shader::uploadUniformMat4(const std::string& name, const glm::mat4& matrix) {
        GLint location = glGetUniformLocation(this->programId, name.c_str());
        this->use();
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void Shader::uploadUniformMVec4(const std::string &name, const glm::vec4 &vec) {
        GLint location = glGetUniformLocation(this->programId, name.c_str());
        this->use();
        glUniform4f(location, vec.x, vec.y, vec.z, vec.x);
    }

    void Shader::uploadUniformFloat(const std::string &name, float val) {
        GLint location = glGetUniformLocation(this->programId, name.c_str());
        this->use();
        glUniform1f(location, val);
    }

    void Shader::uploadUniformInt(const std::string &name, int val) {
        GLint location = glGetUniformLocation(this->programId, name.c_str());
        this->use();
        glUniform1i(location, val);
    }
}