#include <main/game/Game.hpp>

Game::Game() {
    map = Map();
    snake = Snake();
    coin = Coin();
}

void Game::draw() {
    map.draw();
    snake.draw();
    coin.draw();
}

void Game::deleteSelf() {
    map.deleteSelf();
    snake.deleteSelf();
    coin.deleteSelf();
}