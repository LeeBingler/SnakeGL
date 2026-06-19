#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main/States/State.hpp>
#include <main/Game.hpp>
#include <optional>

class GameState : public State {
  static GameState sGameState;

public:
  static GameState* get();

  bool enter();
  bool exit();

  void handleEvent(GLFWwindow* window);
  void update();
  void render();

  std::optional<Game> game;

private:
  GameState();
  ~GameState();
};
