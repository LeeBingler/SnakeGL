#pragma once

#include <main/GUI/Snake.hpp>
#include <main/GUI/Map.hpp>
#include <main/GUI/Coin.hpp>
#include <main/GUI/Timer.hpp>

#include <main/Core/Core.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum Game_state { MENU, IN_GAME, END };

class Game {
public:
  Game(GLFWwindow* window);
  ~Game();
  void update();
  void processInput();
  void draw();

private:
  Map map;
  Coin coin;
  Timer timer;
  Core core;
  Snake snake;
  GLFWwindow* window;
  Game_state game_state;
  double intervale;
  double accumulative;
};
