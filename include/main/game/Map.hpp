#pragma once

#include <array>
#include <cstddef>
#include <main/Shader.hpp>

class Map {
    public:
        std::array<std::array<int, 15>, 17> map;
        size_t nbCols;
        size_t nbRows;
        Shader shader = Shader("resources/shaders/Map/vertex.vs", "resources/shaders/Map/fragment.fs");

        Map();
        int getValue(unsigned int col, unsigned int row);
        std::array<std::array<int, 15>, 17> getMap();
        void draw();
        void deleteSelf();
};