#include <main/GUI/Map.hpp>

Map::Map() {
  nbCols = 15;
  nbRows = 17;

  for (unsigned int i = 0; i < map.size(); i++) {
    map.at(i).fill(0);
  }
}

void Map::draw() { shader.use(); }

void Map::deleteSelf() { shader.deleteProgram(); }

int Map::getValue(unsigned int col, unsigned int row) {
  return map.at(row).at(col);
}

std::array<std::array<int, 15>, 17> Map::getMap() { return map; }
