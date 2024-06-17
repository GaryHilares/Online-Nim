#pragma once
#include "../model/GameState.hpp"
#include "InputScanner.hpp"

class GameController {
private:
    GameState m_game_state;
    InputScanner m_scanner;
public:
    GameController(std::istream& input_stream, std::ostream& output_stream);
    void run();
};
