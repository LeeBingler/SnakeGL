#include <main/States/ExitState.hpp>

ExitState* ExitState::get() {
  return &sExitState;
}

bool ExitState::enter() {
  return true;
}

bool ExitState::exit() {
  return true;
}

void ExitState::handleEvent(GLFWwindow* window) {
  (void)window;
}

void ExitState::update() {}

void ExitState::render() {}

ExitState ExitState::sExitState;

ExitState::ExitState() {}
ExitState::~ExitState() {}
