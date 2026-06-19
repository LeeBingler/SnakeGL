#include <main/States/ExitState.hpp>
#include <main/States/GameState.hpp>
#include <main/StateManager.hpp>
#include <main/Window.hpp>

GameState::GameState() {}
GameState GameState::sGameState;

GameState::~GameState() {}

GameState* GameState::get() {
  return &sGameState;
}

bool GameState::enter() {
  game.emplace(Window::get()->getWindow());
  return true;
}

bool GameState::exit() {
  if (game) {
    game->destroyAll();
  }
  return true;
}

void GameState::handleEvent(GLFWwindow* window) {
  // exit game if player press excape
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    StateManager* state = StateManager::get();
    state->setNextState(ExitState::get());
    return;
  }

  if (game)
    game->processInput();
}

void GameState::update() {
  if (game)
    game->update();
}

void GameState::render() {
  if (game)
    game->draw();
}
