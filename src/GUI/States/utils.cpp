#include <main/States/ScoreState.hpp>
#include <main/States/MenuState.hpp>
#include <main/States/GameState.hpp>
#include <main/States/ExitState.hpp>
#include <main/StateManager.hpp>

void stateGame() {
  StateManager* state = StateManager::get();
  state->setNextState(GameState::get());
}

void stateExit() {
  StateManager* state = StateManager::get();
  state->setNextState(ExitState::get());
}

void stateScore() {
  StateManager* state = StateManager::get();
  state->setNextState(ScoreState::get());
}

void stateMenu() {
  StateManager* state = StateManager::get();
  state->setNextState(MenuState::get());
}
