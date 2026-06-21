#include "main/GUI/Button.hpp"
#include <iostream>
#include <main/States/MenuState.hpp>

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
  play.emplace("PLAY", fontPtr, 400.0, 300.0, 1.0);
  level.emplace("LEVEL", fontPtr, 400.0, 200.0, 1.0);
  quit.emplace("QUIT", fontPtr, 400.0, 100.0, 1.0);

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
    StateManager* state = StateManager::get();
    state->setNextState(ExitState::get());
    return;
  }
}

void MenuState::update() {
  std::cout << Window::get()->getCursor().xPos << " " << Window::get()->getCursor().yPos
            << std::endl;
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
