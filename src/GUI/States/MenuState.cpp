#include <iostream>
#include <main/States/MenuState.hpp>

MenuState::MenuState() {}
MenuState MenuState::sMenuState;

MenuState::~MenuState() {}

MenuState* MenuState::get() {
  return &sMenuState;
}

bool MenuState::enter() {
  return true;
}

bool MenuState::exit() {
  return true;
}

void MenuState::handleEvent(GLFWwindow* window) {
  std::cout << "menustate event" << std::endl;
}

void MenuState::update() {
  std::cout << "menustate update" << std::endl;
}

void MenuState::render() {
  std::cout << "menustate render" << std::endl;
}
