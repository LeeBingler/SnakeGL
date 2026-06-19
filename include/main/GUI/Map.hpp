#pragma once

#include <vector>
#include <main/Shader.hpp>

class Map {
public:
  Shader shader = Shader("resources/shaders/Map/vertex.vs", "resources/shaders/Map/fragment.fs");

  Map();
  void destroyAll();
  void draw(std::vector<std::vector<int>> map);
};
