#pragma once

#include <vector>
#include <main/Shader.hpp>

class Coin {
public:
  Coin();
  ~Coin();
  void draw(std::vector<std::array<int, 2>> coin_position);

private:
  Shader shader = Shader("resources/shaders/Coin/vertex.vs", "resources/shaders/Coin/fragment.fs");
};
