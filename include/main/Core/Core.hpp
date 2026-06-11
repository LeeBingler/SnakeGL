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
  std::vector<std::array<int, 2>> coin_position;
  std::list<struct Snake_part> head;
  std::array<std::array<int, 15>, 17> map;

  Core();
  void update();

private:
  void updateSnakePosition();
};

