#pragma once

#include "glm/detail/type_vec.hpp"
#include <vector>
#include <array>
#include <list>
#include <main/Shader.hpp>
#include <main/OrthoCamera.hpp>

typedef struct Coin_node {
  unsigned int VAO, VBO, EBO;
  glm::mat4 model;
  int modelLoc;
  glm::vec3 translate;
} Coin_node_t;

class Coin {
public:
  Coin(std::vector<std::array<int, 2>> coin_position, glm::vec3 scale_game);
  ~Coin();
  void draw(std::vector<std::array<int, 2>> coin_position, OrthoCamera camera);

private:
  Shader shader = Shader("resources/shaders/Coin/vertex.vs", "resources/shaders/Coin/fragment.fs");

  std::list<Coin_node_t> coin_gui;
  glm::vec3 scale;
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

  Coin_node_t makeNewCoin(int x, int y);
  void updateCoinGUI(std::vector<std::array<int, 2>> coin_position);
};
