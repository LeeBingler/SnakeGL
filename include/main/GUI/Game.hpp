#pragma once

#include <main/GUI/Snake.hpp>
#include <main/GUI/Map.hpp>
#include <main/GUI/Coin.hpp>
#include <main/GUI/Timer.hpp>
#include <main/Shader.hpp>

class Game {
public:
  Map map;
  Snake snake;
  Coin coin;
  Timer timer;

  Game();
  void update();
  void draw();
  void deleteSelf();
};
