#pragma once
#include <vector>
#include <utility>

class GameState {
private:
    std::vector<int> piles;
    int player_number = 0;
public:
    const std::vector<int>& getPiles() const;
    bool isLegalMove(Move move) const;
    void makeMove(Move move);
};
