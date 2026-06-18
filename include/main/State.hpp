#pragma once

enum Game_state { MENU, IN_GAME, END };

class State {
public:
  Game_state current_state{MENU};
};
