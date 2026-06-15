#include <main/GUI/Coin.hpp>

Coin::Coin() {}

void Coin::draw(std::vector<std::vector<int>> coin_position) { shader.use(); }

Coin::~Coin() { shader.deleteProgram(); }
