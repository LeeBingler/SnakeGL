#include <main/Shader.hpp>

#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
  std::string vStringShaderCode = shaderCodeToString(vertexPath);
  std::string fStringShaderCode = shaderCodeToString(fragmentPath);
  const char* vShaderCode = vStringShaderCode.c_str();
  const char* fShaderCode = fStringShaderCode.c_str();

  unsigned int vertex = createShader(GL_VERTEX_SHADER, vShaderCode);
  unsigned int fragment = createShader(GL_FRAGMENT_SHADER, fShaderCode);

  ID = createShaderProgram(vertex, fragment);

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::use() {
  glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setMat4(const std::string& name, glm::mat4 value) {
  int modelLoc = glGetUniformLocation(ID, name.c_str());
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVec3(const std::string& name, glm::vec3 value) {
  int modelLoc = glGetUniformLocation(ID, name.c_str());
  glUniform3fv(modelLoc, 1, glm::value_ptr(value));
}

void Shader::deleteProgram() {
  glDeleteProgram(ID);
}

std::string Shader::shaderCodeToString(const char* path) {
  std::string code = "";
  std::ifstream shaderFile;

  shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    shaderFile.open(path);
    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    code = shaderStream.str();
  } catch (std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    std::cout << path << std::endl;
    (void)e;
  }

  return code;
}

unsigned int Shader::createShader(unsigned int typeShader, const char* shaderCode) {
  int success;
  char infoLog[512];
  unsigned int shader = glCreateShader(typeShader);
  glShaderSource(shader, 1, &shaderCode, NULL);
  glCompileShader(shader);

  // print compile errors if any
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 512, NULL, infoLog);

    if (typeShader == GL_VERTEX_SHADER) {
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    } else {
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
  };

  return shader;
}

unsigned int Shader::createShaderProgram(unsigned int vertexShaderID,
                                         unsigned int fragmentShaderID) {
  int success;
  char infoLog[512];
  unsigned int shaderProgramID = glCreateProgram();

  glAttachShader(shaderProgramID, vertexShaderID);
  glAttachShader(shaderProgramID, fragmentShaderID);
  glLinkProgram(shaderProgramID);

  // print linking errors if any
  glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }

  return shaderProgramID;
}
