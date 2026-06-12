#include <main/Game.hpp>

Game::Game(GLFWwindow* main_window) {
  map = Map();
  coin = Coin();
  timer = Timer();
  core = Core();
  snake = Snake(main_window);

  this->window = main_window;
  game_state = MENU;
  intervale = 1.0;
  accumulative = 0.0;
}

void Game::processInput() {
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    core.snake.front().direction = UP;
  else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    core.snake.front().direction = RIGHT;
  else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    core.snake.front().direction = DOWN;
  else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    core.snake.front().direction = LEFT;
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
  coin.draw(core.coin_position);
  snake.draw(core.snake);
}

Game::~Game() {
  map.deleteSelf();
  snake.deleteSelf();
  coin.deleteSelf();
}
