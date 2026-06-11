#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

Core::Core() {
  srand((unsigned)time(0));

  score = 0;
  head.push_back({.direction = RIGHT, .position = {0, 0}});

  for (int i = 0; i < 3; i++) {
    coin_position.push_back({rand() % 17, rand() % 15});
  }

  for (unsigned int i = 0; i < map.max_size(); i++) {
    map[i].fill(0);
  }

  // one is for the snake position
  map[0][0] = 1;
}

void Core::updateSnakePosition() {
  Snake_part_t& node = head.front();
  std::array<int, 2> positionSnake = node.position;

  std::array<int, 2> newPosition;
  switch (node.direction) {
  case LEFT:
    newPosition = {positionSnake[0] - 1, positionSnake[1]};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    node.position = newPosition;
    break;
  case RIGHT:
    newPosition = {positionSnake[0] + 1, positionSnake[1]};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    node.position = newPosition;
    break;
  case UP:
    newPosition = {positionSnake[0], positionSnake[1] - 1};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    node.position = newPosition;
    break;
  case DOWN:
    newPosition = {positionSnake[0], positionSnake[1] + 1};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    node.position = newPosition;
    break;

  default:
    break;
  }
}

void Core::update() { updateSnakePosition(); }
