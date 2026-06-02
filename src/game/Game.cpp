#include <main/game/Game.hpp>

Game::Game() {
    map = Map();
    snake = Snake();
    coin = Coin();
}

void Game::update(float deltaTime) {

}

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