#pragma once
#include <ostream>

class GameState;

class GameView {
private:
    const GameState& m_game_state;
    std::ostream& m_output_stream;

public:
    GameView(const GameState& game_state, std::ostream& output_stream);
    void outputWelcome();
    void outputGameState();
    void outputPrompt();
};