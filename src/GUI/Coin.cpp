#include <cstdlib>
#include <ctime>
#include <main/GUI/Coin.hpp>

Coin::Coin() {
  srand(time(0));
  position.at(0) = rand() % 15;
  position.at(1) = rand() % 17;
}

void Coin::draw() { shader.use(); }

void Coin::deleteSelf() { shader.deleteProgram(); }
