#pragma once

#include <vector>

enum Direction_keys { UP, DOWN, LEFT, RIGHT };

struct Snake_part {
  Direction_keys direction;
  std::vector<int> position;
  struct Snake_part *next;
  struct Snake_part *prev;
};

class Core {
public:
  int score;
  std::vector<std::vector<int>> coin_position;
  struct Snake_part *head;

  Core();
};
