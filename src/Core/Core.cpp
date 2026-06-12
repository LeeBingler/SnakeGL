#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

#include <iostream>

Core::Core() {
  srand((unsigned)time(0));

  score = 0;
  snake.push_back({.direction = RIGHT, .position = {1, 0}});

  for (int i = 0; i < 3; i++) {
    coin_position.push_back({rand() % 17, rand() % 15});
  }

  for (unsigned int i = 0; i < map.max_size(); i++) {
    map[i].fill(0);
  }

  // one is for the snake position
  map[1][0] = 1;

  Core::addNodeSnake();
}

void Core::addNodeSnake() {
  Snake_part_t tail = snake.back();
  Snake_part_t new_node = {.direction = tail.direction, .position = tail.position};

  switch (tail.direction) {
  case LEFT:
    new_node.position[0] += 1;
    break;
  case RIGHT:
    new_node.position[0] -= 1;
    break;
  case UP:
    new_node.position[1] += 1;
    break;
  case DOWN:
    new_node.position[1] -= 1;
    break;

  default:
    break;
  }
  map[new_node.position[0]][new_node.position[1]] = 1;
  snake.push_back(new_node);
}

void updateHead(Snake_part_t& head, std::array<int, 2> positionSnake,
                std::array<std::array<int, 15>, 17>& map) {
  std::array<int, 2> newPosition;
  switch (head.direction) {
  case LEFT:
    newPosition = {positionSnake[0] - 1, positionSnake[1]};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    head.position = newPosition;
    break;
  case RIGHT:
    newPosition = {positionSnake[0] + 1, positionSnake[1]};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    head.position = newPosition;
    break;
  case UP:
    newPosition = {positionSnake[0], positionSnake[1] - 1};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    head.position = newPosition;
    break;
  case DOWN:
    newPosition = {positionSnake[0], positionSnake[1] + 1};
    map[newPosition[0]][newPosition[1]] = 1;
    map[positionSnake[0]][positionSnake[1]] = 0;
    head.position = newPosition;
    break;

  default:
    break;
  }
}

void Core::updateSnakePosition() {
  std::list<Snake_part_t>::iterator it;
  std::array<int, 2> prev;

  for (it = snake.begin(); it != snake.end(); it++) {
    Snake_part_t& head = *it;
    std::array<int, 2> positionSnake = head.position;

    if (it == snake.begin()) {
      updateHead(head, positionSnake, map);
    } else {
      map[prev[0]][prev[1]] = 1;
      map[positionSnake[0]][positionSnake[1]] = 0;
      head.position = prev;
    }

    prev = positionSnake;
  }
}

void Core::update() {
  updateSnakePosition();

  for (int y = 0; y < map[0].size(); y++) {
    for (int x = 0; x < map[y].size(); x++) {
      std::cout << map[x][y];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
