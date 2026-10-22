#include <main/GUI/Button.hpp>
#include <main/States/ScoreState.hpp>
#include <main/States/GameState.hpp>
#include <main/States/ExitState.hpp>
#include <main/States/utils.hpp>
#include <main/StateManager.hpp>
#include <main/Window.hpp>

ScoreState::ScoreState() {}
ScoreState ScoreState::sScoreState;

ScoreState::~ScoreState() {}

ScoreState* ScoreState::get() {
  return &sScoreState;
}

bool ScoreState::enter() {
  font.emplace("resources/font/aileron.regular.otf");

  GLFWwindow* window = Window::get()->getWindow();
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  TrueTypeFont* fontPtr = &font.value();

  again.emplace("Again", fontPtr, width / 2. - Button::width / 2, height / 2., 1.0, stateGame);
  menu.emplace("Menu", fontPtr, width / 2. - Button::width / 2., height / 2. - Button::height * 2,
               1.0, stateMenu);

  return true;
}

bool ScoreState::exit() {
  if (font)
    font->destroyAll();

  return true;
}

void ScoreState::handleEvent(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    stateExit();
    return;
  }
}

void ScoreState::update() {
  if (menu)
    menu->update();
  if (again)
    again->update();
}

void ScoreState::render() {
  if (menu)
    menu->draw();
  if (again)
    again->draw();
}
