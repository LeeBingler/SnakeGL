#include <main/GUI/Map.hpp>

Map::Map() {}

void Map::draw(std::vector<std::vector<int>> map) { shader.use(); }

Map::~Map() { shader.deleteProgram(); }
