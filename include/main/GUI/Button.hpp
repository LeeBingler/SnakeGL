#pragma once

#include <main/Shader.hpp>
#include "../../../src/font/TrueTypeFont.hpp"
#include <string>
#include <functional>

class Button {
public:
  Button(std::string s, TrueTypeFont* f, float x, float y, float scale, std::function<void()> func);
  Button(std::string s, TrueTypeFont* f, float x, float y, float scale);
  void destroyAll();
  void update();
  void draw();
  static constexpr float width = 160.0f;
  static constexpr float height = 50.0f;

private:
  // Font
  std::string string;
  TrueTypeFont* font;
  float x, y, scale;
  std::function<void()> onPress = nullptr;
  bool isPressed;
  bool wasPressed;
  bool isHovered;

  // Shaders
  Shader shaderFont =
      Shader("resources/shaders/font/vertex.vs", "resources/shaders/font/fragment.fs");
  Shader shaderBg =
      Shader("resources/shaders/Button/vertex.vs", "resources/shaders/Button/fragment.fs");

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
  glm::mat4 projection;
  glm::mat4 view;
};
