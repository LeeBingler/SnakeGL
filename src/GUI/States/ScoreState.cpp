#include <main/GUI/Button.hpp>

#include <main/States/ScoreState.hpp>
#include <main/States/GameState.hpp>
#include <main/States/ExitState.hpp>
#include <main/StateManager.hpp>
#include <main/Window.hpp>

ScoreState::ScoreState() {}
ScoreState ScoreState::sScoreState;

ScoreState::~ScoreState() {}

ScoreState* ScoreState::get() {
  return &sScoreState;
}

void playAgain() {
  StateManager* state = StateManager::get();
  state->setNextState(GameState::get());
}

bool ScoreState::enter() {
  font.emplace("resources/font/aileron.regular.otf");

  GLFWwindow* window = Window::get()->getWindow();
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  TrueTypeFont* fontPtr = &font.value();

  score.emplace("Score", fontPtr, 0.0, 0.0, 1.0, playAgain);
  again.emplace("Again", fontPtr, width / 2, height / 2 - 10, 1.0, playAgain);

  return true;
}

bool ScoreState::exit() {
  if (font)
    font->destroyAll();

  return true;
}

void ScoreState::handleEvent(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    StateManager* state = StateManager::get();
    state->setNextState(ExitState::get());
    return;
  }
}

void ScoreState::update() {
  if (score)
    score->update();
}

void ScoreState::render() {
  if (score)
    score->draw();
}
