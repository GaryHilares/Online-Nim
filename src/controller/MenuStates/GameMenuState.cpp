#include "../../../include/controller/MenuStates/GameMenuState.hpp"
#include "../../../include/controller/MenuContext.hpp"

GameMenuState::GameMenuState(std::ostream& output_stream, Player* player_1, Player* player_2)
    : m_state()
    , m_player_1(player_1)
    , m_player_2(player_2)
    , m_view(m_state, output_stream)
{
}

void GameMenuState::run(MenuContext& menu_context)
{
    m_view.outputWelcome();
    while (!m_state.hasGameEnded()) {
        m_view.outputGameState();
        std::unique_ptr<Player>& current_player = m_state.getTurn() == 1 ? m_player_1 : m_player_2;
        std::optional<Move> move;
        while (!move.has_value() || !m_state.isLegalMove(move.value())) {
            m_view.outputPrompt(current_player);
            move = current_player->inputMove();
        }
        m_state.makeMove(move.value());
    }
    m_view.outputWinner();
    menu_context.setExit();
}