#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

#include <iostream>

Core::Core() {
  srand((unsigned)time(0));

  Snake_part_t head = {.direction = RIGHT, .position = {2, 0}};
  score = 0;
  snake.push_back(head);

  for (int i = 0; i < 3; i++) {
    coin_position.push_back({rand() % 17, rand() % 15});
  }

  for (unsigned int i = 0; i < map.max_size(); i++) {
    map[i].fill(0);
  }

  // one is for the snake position
  map[head.position[0]][head.position[1]] = 1;

  Core::addNodeSnake();
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
  std::cout << new_node.position[0] << new_node.position[1] << std::endl;
  map[new_node.position[0]][new_node.position[1]] = 1;
  snake.push_back(new_node);
}

void Core::processInput(Direction_keys new_direction) { wanted_direction = new_direction; }

std::array<int, 2> getNewPosition(Direction_keys direction, std::array<int, 2> positionSnake) {
  std::array<int, 2> newPosition;
  switch (direction) {
  case LEFT:
    newPosition = {positionSnake[0] - 1, positionSnake[1]};
    break;
  case RIGHT:
    newPosition = {positionSnake[0] + 1, positionSnake[1]};
    break;
  case UP:
    newPosition = {positionSnake[0], positionSnake[1] - 1};
    break;
  case DOWN:
    newPosition = {positionSnake[0], positionSnake[1] + 1};
    break;

  default:
    break;
  }

  return newPosition;
}

void Core::updateHead(Snake_part_t& head, std::array<int, 2> positionSnake) {
  std::array<int, 2> newPosition = getNewPosition(wanted_direction, positionSnake);

  // Check if the head is trying to move on a node
  auto it = std::next(snake.begin());
  for (; it != snake.end(); it++) {
    Snake_part_t node = *it;

    if (node.position[0] == newPosition[0] && node.position[1] == newPosition[1]) {
      wanted_direction = head.direction;
      newPosition = getNewPosition(wanted_direction, positionSnake);
    }
  }

  map[newPosition[0]][newPosition[1]] = 1;
  map[positionSnake[0]][positionSnake[1]] = 0;
  head.position = newPosition;
  head.direction = wanted_direction;
}

void Core::updateSnakePosition() {
  std::list<Snake_part_t>::iterator it;
  std::array<int, 2> prevPosition;
  Direction_keys prevDirection;

  for (it = snake.begin(); it != snake.end(); it++) {
    Snake_part_t& node = *it;
    std::array<int, 2> positionSnake = node.position;
    Direction_keys directionSnake = node.direction;

    if (it == snake.begin()) {
      updateHead(node, positionSnake);
      directionSnake = node.direction;
    } else {
      map[prevPosition[0]][prevPosition[1]] = 1;
      map[positionSnake[0]][positionSnake[1]] = 0;
      node.position = prevPosition;
      node.direction = prevDirection;
    }

    prevPosition = positionSnake;
    prevDirection = directionSnake;
  }
}

void Core::update() {
  updateSnakePosition();

  for (unsigned int y = 0; y < map[0].size(); y++) {
    for (unsigned int x = 0; x < map[y].size(); x++) {
      std::cout << map[x][y];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
