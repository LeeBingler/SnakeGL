#pragma once

#include <main/game/Snake.hpp>
#include <main/game/Map.hpp>
#include <main/game/Coin.hpp>
#include <main/Shader.hpp>

class Game {
    public:
        Map map;
        Snake snake;
        Coin coin;

        void draw();
        Game();
        void deleteSelf();
};