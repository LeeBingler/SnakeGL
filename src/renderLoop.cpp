#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <main/GUI/Game.hpp>

// close window when escape is press
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void updateDelta(float deltaTime, float lastFrame) {
  float currentFrame = glfwGetTime();
  deltaTime = currentFrame - lastFrame;
  lastFrame = currentFrame;
}

// Render loop
void renderLoop(GLFWwindow *window) {
  Game myGame = Game();
  float deltaTime = 0.0f;
  float lastFrame = 0.0f;

  // render loop
  while (!glfwWindowShouldClose(window)) {
    updateDelta(deltaTime, lastFrame);
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    myGame.update(deltaTime);
    myGame.draw();

    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  myGame.deleteSelf();
}
