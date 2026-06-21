#pragma once

#include <main/Shader.hpp>
#include "../../../src/font/TrueTypeFont.hpp"
#include <string>

class Button {
public:
  Button(std::string string, TrueTypeFont* font, float x, float y, float scale);
  void destroyAll();
  void update();
  void draw();

private:
  // Font
  std::string string;
  TrueTypeFont* font;
  int x, y, z;
  float scale;

  // Shaders
  Shader shaderFont =
      Shader("resources/shaders/font/vertex.vs", "resources/shaders/font/fragment.fs");
  Shader shaderBg =
      Shader("resources/shaders/Snake/vertex.vs", "resources/shaders/Snake/fragment.fs");

  // data forto draw rectangle
  float vertices[12] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };
  unsigned int indices[6] = {
      0, 1, 3, // first Triangle
      1, 2, 3  // second Triangle
  };

  // Model
  unsigned int VAO, VBO, EBO;
  glm::mat4 model;
  glm::mat4 projection;
  glm::mat4 view;
};
