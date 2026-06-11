#include <main/GUI/Map.hpp>

Map::Map() {}

void Map::draw(std::array<std::array<int, 15>, 17> map) { shader.use(); }

void Map::deleteSelf() { shader.deleteProgram(); }
