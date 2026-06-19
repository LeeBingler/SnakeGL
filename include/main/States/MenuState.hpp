#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main/States/State.hpp>

class MenuState : public State {
public:
  static MenuState* get();

  bool enter();
  bool exit();

  void handleEvent(GLFWwindow* window);
  void update();
  void render();

private:
  static MenuState sMenuState;

  MenuState();
  ~MenuState();
};
