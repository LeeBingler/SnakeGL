#pragma once

#include <array>
#include <main/Shader.hpp>

class Coin {
    public:
        std::array<int, 2> position;
        Shader shader = Shader("resources/shaders/Coin/vertex.vs", "resources/shaders/Coin/fragment.fs");

        Coin();
        void draw();
        void deleteSelf();
};