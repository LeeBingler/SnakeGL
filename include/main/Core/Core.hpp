#pragma once

#include <array>
#include <list>
#include <vector>

enum Direction_keys { UP, DOWN, LEFT, RIGHT };

typedef struct Snake_part {
  Direction_keys direction;
  std::array<int, 2> position;
} Snake_part_t;

class Core {
public:
  int score;
  int width_map{15};
  int height_map{17};
  Direction_keys wanted_direction;
  std::vector<std::array<int, 2>> coin_position;
  std::list<struct Snake_part> snake;
  std::vector<std::vector<int>> map;

  Core();
  void update();
  void processInput(Direction_keys new_direction);

private:
  void updateHead(Snake_part_t& node, std::array<int, 2> positionSnake);
  void updateSnake();
  void addNodeSnake();

  void updateCoin(std::array<int, 2> newPosition);
};
