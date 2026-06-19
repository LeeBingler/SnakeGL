#include <main/StateManager.hpp>
#include <main/States/ExitState.hpp>

StateManager::StateManager() {};
StateManager StateManager::sStateManager;

StateManager* StateManager::get() {
  return &sStateManager;
}

void StateManager::setNextState(State* newState) {
  if (nextState != ExitState::get())
    nextState = newState;
}

void StateManager::changeState() {
  // If the state needs to be changed
  if (nextState != NULL) {
    if (currentState)
      currentState->exit();

    nextState->enter();

    // Change the current state ID
    currentState = nextState;
    nextState = NULL;
  }
}
