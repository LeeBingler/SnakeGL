#include "main/GUI/Timer.hpp"
#include <main/GUI/Game.hpp>

Game::Game() {
  map = Map();
  snake = Snake();
  coin = Coin();
  timer = Timer();
}

void Game::update() { timer.updateDelta(); }

void Game::draw() {
  map.draw();
  coin.draw();
  snake.draw();
}

void Game::deleteSelf() {
  map.deleteSelf();
  snake.deleteSelf();
  coin.deleteSelf();
}
