#include <main/Core/Core.hpp>
#include <cstdlib> 
#include <ctime>

Core::Core() {
  srand((unsigned) time(0));

  score = 0;
  head.push_back({ 
    .direction = LEFT,
    .position = {0, 0}
  });

  for (int i = 0; i < 3; i++) {
    coin_position.push_back({
      rand() % 17,
      rand() % 15
    });
  }

}
