#include <main/game/Snake.hpp>

Snake::Snake() {
    positionHead.fill(0);
}

void Snake::draw() {
    shader.use();
}

void Snake::deleteSelf() {
    shader.deleteProgram();
}