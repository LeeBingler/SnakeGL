#include <main/GUI/Button.hpp>
#include <main/States/MenuState.hpp>
#include <main/States/utils.hpp>

#include <main/States/ExitState.hpp>
#include <main/States/GameState.hpp>
#include <main/StateManager.hpp>
#include <main/Window.hpp>

MenuState::MenuState() {}
MenuState MenuState::sMenuState;

MenuState::~MenuState() {}

MenuState* MenuState::get() {
  return &sMenuState;
}

bool MenuState::enter() {
  font.emplace("resources/font/aileron.regular.otf");
  TrueTypeFont* fontPtr = &font.value();

  GLFWwindow* window = Window::get()->getWindow();
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  const double middleBtnX = width / 2. - Button::width / 2.;
  const double middleBtnY = height / 2. - Button::height / 2. - 100;

  play.emplace(" PLAY", fontPtr, middleBtnX, middleBtnY + 100., 1.0, stateGame);
  level.emplace("LEVEL", fontPtr, middleBtnX, middleBtnY, 1.0, stateExit);
  quit.emplace(" QUIT", fontPtr, middleBtnX, middleBtnY - 100, 1.0, stateExit);

  return true;
}

bool MenuState::exit() {
  if (font)
    font->destroyAll();

  if (play)
    play->destroyAll();
  if (level)
    level->destroyAll();
  if (quit)
    quit->destroyAll();
  return true;
}

void MenuState::handleEvent(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    stateExit();
    return;
  }
}

void MenuState::update() {
  if (play)
    play->update();
  if (level)
    level->update();
  if (quit)
    quit->update();
}

void MenuState::render() {
  if (play)
    play->draw();
  if (level)
    level->draw();
  if (quit)
    quit->draw();
}
