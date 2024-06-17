#include "../../include/model/GameState.hpp"
#include <cassert>

bool GameState::areAllPilesEmpty() const
{
    for (int pile : m_piles) {
        if (pile != 0) {
            return false;
        }
    }
    return true;
}

GameState::GameState()
    : m_piles(5, 50)
    , m_turn(1)
    , m_has_game_ended(false)
{
}

const std::vector<int>& GameState::getPiles() const
{
    return m_piles;
}

int GameState::getTurn() const
{
    return m_turn;
}

bool GameState::isLegalMove(Move move) const
{
    const int pile_number = move.getPileNumber();
    const int num_to_remove = move.getNumToRemove();
    return !m_has_game_ended && pile_number < m_piles.size() && pile_number >= 0
        && num_to_remove <= m_piles[move.getPileNumber()] && num_to_remove > 0;
}

void GameState::makeMove(Move move)
{
    assert(isLegalMove(move));
    m_piles[move.getPileNumber()] -= move.getNumToRemove();

    if (areAllPilesEmpty()) {
        m_has_game_ended = true;
    } else {
        m_turn = m_turn == 1 ? 2 : 1;
    }
}

bool GameState::hasGameEnded() const
{
    return m_has_game_ended;
}
