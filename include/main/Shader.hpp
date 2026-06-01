#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <string>

class Shader {
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);
        void use();
        void deleteProgram();
        void setBool(const std::string &name, bool value);
        void setInt(const std::string &name, int value);
        void setFloat(const std::string &name, float value);
        void setMat4(const std::string &name, glm::mat4 value);

    private:
        std::string shaderCodeToString (const char *path);
        unsigned int createShaderProgram(unsigned int vertexShaderID, unsigned int fragmentShaderID);
        unsigned int createShader(unsigned int typeShader, const char *shaderCode);
};