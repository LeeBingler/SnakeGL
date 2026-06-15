#include <array>
#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

#include <iostream>

Core::Core() : score(0), wanted_direction(RIGHT) {
  srand((unsigned)time(0));

  Snake_part_t head = {.direction = RIGHT, .position = {2, 0}};
  snake.push_back(head);

  for (unsigned int i = 0; i < map.max_size(); i++) {
    map[i].fill(0);
  }

  // 2 is for the coin position
  for (int i = 0; i < 3; i++) {
    std::array<int, 2> position{rand() % 17, rand() % 15};
    map[position[0]][position[1]] = 2;
    coin_position.push_back({position});
  }

  // 1 is for the snake position
  map[head.position[0]][head.position[1]] = 1;

  Core::addNodeSnake();
  Core::addNodeSnake();
}

void Core::processInput(Direction_keys new_direction) { wanted_direction = new_direction; }

void Core::update() {
  updateSnake();

  for (unsigned int y = 0; y < map[0].size(); y++) {
    for (unsigned int x = 0; x < map[y].size(); x++) {
      std::cout << map[x][y];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
