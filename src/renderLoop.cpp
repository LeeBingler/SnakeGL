#include "main/Window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <main/Game.hpp>
#include <main/StateManager.hpp>
#include <main/States/GameState.hpp>
#include <main/States/ExitState.hpp>

// Render loop
void renderLoop() {
  GLFWwindow* window = Window::get()->getWindow();
  StateManager* stateManager = StateManager::get();
  State* currentState = stateManager->getCurrentState();

  stateManager->setNextState(GameState::get());
  stateManager->changeState();

  // render loop
  while (currentState != ExitState::get()) {
    currentState = stateManager->getCurrentState();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    currentState->handleEvent(window);
    currentState->update();
    stateManager->changeState();
    currentState->render();

    glfwPollEvents();
    glfwSwapBuffers(window);
  }
}
