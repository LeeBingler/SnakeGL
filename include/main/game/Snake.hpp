#pragma once

#include <array>
#include <main/Shader.hpp>

class Snake {
    public:
        std::array<int, 2> positionHead;
        Shader shader = Shader("resources/shaders/Snake/vertex.vs", "resources/shaders/Snake/fragment.fs");

        Snake();
        void draw();
        void deleteSelf();
};