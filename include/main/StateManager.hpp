#pragma once

#include <main/States/State.hpp>

class StateManager {
public:
  static StateManager* get();
  void setNextState(State* nextState);
  void changeState();
  State* getCurrentState() const {
    return currentState;
  }

private:
  StateManager();
  static StateManager sStateManager;
  State* nextState = nullptr;
  State* currentState = nullptr;
};
