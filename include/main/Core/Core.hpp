#pragma once

#include <array>
#include <list>
#include <vector>

enum Direction_keys { UP, DOWN, LEFT, RIGHT };

struct Snake_part {
  Direction_keys direction;
  std::array<int, 2> position;
};

class Core {
public:
  int score;
  std::vector<std::array<int, 2>> coin_position;
  std::list<struct Snake_part> head;

  Core();
};
