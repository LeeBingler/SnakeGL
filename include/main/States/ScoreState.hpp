#pragma once

#include <main/States/State.hpp>

#include <main/GUI/Button.hpp>
#include "../../../src/font/TrueTypeFont.hpp"
#include <optional>

class ScoreState : public State {
public:
  static ScoreState* get();

  bool enter();
  bool exit();

  void handleEvent(GLFWwindow* window);
  void update();
  void render();

private:
  static ScoreState sScoreState;

  std::optional<TrueTypeFont> font;
  std::optional<Button> menu;
  std::optional<Button> again;
  std::optional<Button> score;

  ScoreState();
  ~ScoreState();
};
