#pragma once
#include "Move.hpp"
#include <utility>
#include <vector>

class GameState {
private:
    std::vector<int> m_piles;
    int m_turn;
    bool m_has_game_ended;
    bool areAllPilesEmpty() const;

public:
    GameState();
    const std::vector<int>& getPiles() const;
    int getTurn() const;
    bool isLegalMove(Move move) const;
    void makeMove(Move move);
    bool hasGameEnded() const;
};
