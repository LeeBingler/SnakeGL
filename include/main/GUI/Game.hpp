#pragma once

#include <main/GUI/Snake.hpp>
#include <main/GUI/Map.hpp>
#include <main/GUI/Coin.hpp>
#include <main/Shader.hpp>

class Game {
public:
  Map map;
  Snake snake;
  Coin coin;

  Game();
  void update(float deltaTime);
  void draw();
  void deleteSelf();
};
