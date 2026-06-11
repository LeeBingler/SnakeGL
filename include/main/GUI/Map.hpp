#pragma once

#include <array>
#include <main/Shader.hpp>

class Map {
public:
  Shader shader = Shader("resources/shaders/Map/vertex.vs",
                         "resources/shaders/Map/fragment.fs");

  Map();
  void draw(std::array<std::array<int, 15>, 17> map);
  void deleteSelf();
};
