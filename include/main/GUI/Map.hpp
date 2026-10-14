#pragma once

#include <vector>
#include <main/Shader.hpp>
#include <main/OrthoCamera.hpp>

class Map {
public:
  std::vector<std::vector<int>> &map;

  Shader shader = Shader("resources/shaders/Map/vertex.vs", "resources/shaders/Map/fragment.fs");

  unsigned int VAO, VBO, EBO;
  glm::mat4 model;
  glm::vec3 translate;
  const float vertices[12] = {
      0.5f,  0.5f,  0.0f, // top right
      0.5f,  -0.5f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f  // top left
  };
  const unsigned int indices[6] = {
      0, 1, 3, // first Triangle
      1, 2, 3  // second Triangle
  };

  glm::mat4 projection, view;

  Map(std::vector<std::vector<int>> &map);
  Map(glm::vec3 scale_square_game, std::vector<std::vector<int>> &map);
  void destroyAll();
  void draw(OrthoCamera& camera);
};
