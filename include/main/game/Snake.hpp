#pragma once

#include <array>
#include <main/Shader.hpp>

enum SnakeMovement {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Snake {
    public:
        // Game logic
        std::array<int, 2> positionHead;
        SnakeMovement currentMovment = LEFT;

        // Model
        Shader shader = Shader("resources/shaders/Snake/vertex.vs", "resources/shaders/Snake/fragment.fs");
        unsigned int VAO, VBO, EBO;
        glm::mat4 projection, view, model;
        int projLoc, viewLoc, modelLoc;

        Snake();
        void draw();
        void update();
        void deleteSelf();

    private:
        void setModel();
        void setMatrix();
};