#include "../../include/view/GameView.hpp"
#include "../../include/model/GameState.hpp"
#include <cassert>

GameView::GameView(const GameState& game_state, std::ostream& output_stream)
    : m_game_state(game_state)
    , m_output_stream(output_stream)
{
}

void GameView::outputWelcome()
{
    m_output_stream << "Welcome to a 2-player game of Nim!" << std::endl;
}

void GameView::outputGameState()
{
    const std::vector<int>& piles = m_game_state.getPiles();
    m_output_stream << "piles = [";
    bool first = true;
    for (int pile : piles) {
        if (!first) {
            m_output_stream << ", ";
        } else {
            first = false;
        }
        m_output_stream << pile;
    }
    m_output_stream << "]\nPlayer " << m_game_state.getTurn() << " to play." << std::endl;
}

void GameView::outputPrompt(const std::unique_ptr<PlayerInput>& player)
{
    m_output_stream << player->getPrompt() << std::flush;
}

void GameView::outputWinner()
{
    assert(m_game_state.hasGameEnded());
    m_output_stream << "Player " << m_game_state.getTurn() << " won the game!" << std::endl;
}