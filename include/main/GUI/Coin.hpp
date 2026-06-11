#pragma once

#include <array>
#include <vector>
#include <main/Shader.hpp>

class Coin {
public:
  std::array<int, 2> position;
  Shader shader = Shader("resources/shaders/Coin/vertex.vs",
                         "resources/shaders/Coin/fragment.fs");

  Coin();
  void draw(std::vector<std::array<int, 2>> coin_position);
  void deleteSelf();
};
