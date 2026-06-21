#pragma once

#include "glm/detail/type_vec.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main/States/State.hpp>

#include <main/GUI/Button.hpp>
#include <optional>

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

  std::optional<TrueTypeFont> font;
  glm::vec3 colorText = glm::vec3(1.0, 1.0, 1.0);
  glm::vec3 colorBg = glm::vec3(0.0, 0.0, 0.0);

  std::optional<Button> play;
  std::optional<Button> level;
  std::optional<Button> quit;
};
