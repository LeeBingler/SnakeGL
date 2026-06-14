#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

#include <iostream>

Core::Core() : score(0) {
  srand((unsigned)time(0));

  Snake_part_t head = {.direction = RIGHT, .position = {2, 0}};
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

void Core::processInput(Direction_keys new_direction) { wanted_direction = new_direction; }

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
