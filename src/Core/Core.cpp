#include <array>
#include <cstdlib>
#include <ctime>
#include <main/Core/Core.hpp>

#include <iostream>

Core::Core() : score(0), wanted_direction(RIGHT) {
  srand((unsigned)time(0));

  Snake_part_t head = {.direction = RIGHT, .position = {0, 2}};
  snake.push_back(head);

  map.resize(height_map);

  for (int i = 0; i < height_map; i++) {
    map[i].resize(width_map);
    std::fill(map[i].begin(), map[i].end(), 0);
  }

  // 2 is for the coin position
  for (int i = 0; i < 3; i++) {
    std::array<int, 2> position{rand() % height_map, rand() % width_map};
    map[position[0]][position[1]] = 2;
    coin_position.push_back(position);
  }

  // 1 is for the snake position
  map[head.position[0]][head.position[1]] = 1;

  Core::addNodeSnake();
  Core::addNodeSnake();
}

void Core::processInput(Direction_keys new_direction) {
  wanted_direction = new_direction;
}

void Core::updateCoin() {
  // In all coin_position, if in map the coin doesnt exist, replace it
  for (auto& position : coin_position) {
    if (map[position[0]][position[1]] == 2)
      continue;

    do {
      position[0] = rand() % height_map;
      position[1] = rand() % width_map;
    } while (map[position[0]][position[1]] != 0);

    map[position[0]][position[1]] = 2;
  }
}

void Core::update() {
  updateSnake();
  updateCoin();

  for (int y = 0; y < height_map; y++) {
    for (int x = 0; x < width_map; x++) {
      std::cout << map[y][x];
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
