#pragma once

#include "glm/detail/type_vec.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <main/States/State.hpp>
#include "../../../src/Utils/SpriteRenderer.hpp"
#include "main/Shader.hpp"

#include <main/GUI/Button.hpp>
#include <main/Texture2D.hpp>
#include <optional>
#include <list>

class MenuState : public State {
public:
  static MenuState* get();

  bool enter() override;
  bool exit() override;

  void handleEvent(GLFWwindow* window) override;
  void update() override;
  void render() override;

private:
  static MenuState sMenuState;

  MenuState();
  ~MenuState();

  std::optional<TrueTypeFont> font;
  glm::vec3 colorText = glm::vec3(1.0, 1.0, 1.0);
  glm::vec3 colorBg = glm::vec3(0.0, 0.0, 0.0);

  std::optional<Shader> shaderSpriteRenderer;
  std::optional<SpriteRenderer> spriteRenderer;
  std::optional<std::list<Texture2D>> texturesButtons;
  glm::mat4 projection{1.0};

  std::optional<Button> play;
  std::optional<Button> level;
  std::optional<Button> quit;
};
