#pragma once

#include <main/States/State.hpp>

class ExitState : public State {
public:
  static ExitState* get();

  bool enter();
  bool exit();

  void handleEvent(GLFWwindow* window);
  void update();
  void render();

private:
  static ExitState sExitState;

  ExitState();
  ~ExitState();
};
