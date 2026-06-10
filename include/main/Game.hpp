#pragma once

#include <main/GUI/Snake.hpp>
#include <main/GUI/Map.hpp>
#include <main/GUI/Coin.hpp>
#include <main/GUI/Timer.hpp>

#include <main/Core/Core.hpp>

enum Game_state { MENU, IN_GAME, END };

class Game {
public:
  Map map;
  Snake snake;
  Coin coin;
  Timer timer;


  Game_state game_state;
  Core core;

  Game();
  void update();
  void draw();
  void deleteSelf();
};
