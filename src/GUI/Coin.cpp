#include <main/GUI/Coin.hpp>

Coin::Coin() {}

void Coin::draw(std::vector<std::array<int, 2>> coin_position) {
  shader.use();
}

Coin::~Coin() {
  shader.deleteProgram();
}
