#include "glm/detail/type_vec.hpp"
#include "main/Core/Core.hpp"
#include <main/Game.hpp>

glm::vec3 Game::computeScale(GLFWwindow* window) {
  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);
  return glm::vec3(width / 15.0, height / 17.0, 1.0f);
}

Game::Game(GLFWwindow* main_window)
    : core(), window(main_window), scale_square_game(Game::computeScale(main_window)),
      intervale(1.0), accumulative(0.0), camera(), timer(), map(),
      coin(core.coin_position, scale_square_game),
      snake(scale_square_game, core.snake.front().position) {

  int width, height = 0;
  glfwGetWindowSize(window, &width, &height);

  camera.updateProjectionMatrix(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f,
                                0.1f, 100.0f);
}

void Game::processInput() {
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    core.processInput(UP);
  else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    core.processInput(RIGHT);
  else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    core.processInput(DOWN);
  else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    core.processInput(LEFT);
}

void Game::update() {
  timer.updateDelta();
  accumulative += timer.deltaTime;

  if (accumulative >= intervale) {
    core.update();
    accumulative -= intervale;
  }
}

void Game::draw() {
  map.draw(core.map);
  coin.draw(core.coin_position, camera);
  snake.draw(core.snake, camera);
}

void Game::destroyAll() {
  map.destroyAll();
  coin.destroyAll();
  snake.destroyAll();
}
