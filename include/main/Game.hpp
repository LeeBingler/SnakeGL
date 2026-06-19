#pragma once

#include <glm/glm.hpp>
#include <main/GUI/Snake.hpp>
#include <main/GUI/Map.hpp>
#include <main/GUI/Coin.hpp>
#include <main/GUI/Timer.hpp>
#include <main/OrthoCamera.hpp>

#include <main/Core/Core.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game {
public:
  Game(GLFWwindow* window);
  ~Game();
  void update();
  void processInput();
  void draw();

private:
  Core core;
  GLFWwindow* window;

  static glm::vec3 computeScale(GLFWwindow* window);
  glm::vec3 scale_square_game;
  double intervale;
  double accumulative;
  OrthoCamera camera;
  Timer timer;
  Map map;
  Coin coin;
  Snake snake;
};
