#include "../../include/controller/GameController.hpp"
#include "../../include/controller/MenuContext.hpp"

GameController::GameController(std::istream& input_stream, std::ostream& output_stream)
    : m_state()
    , m_view(m_state, output_stream)
    , m_scanner(input_stream)
{
}

void GameController::run(MenuContext& menu_context)
{
    m_view.outputWelcome();
    while (!m_state.hasGameEnded()) {
        m_view.outputGameState();
        std::optional<Move> input_move;
        while (!input_move.has_value() || !m_state.isLegalMove(input_move.value())) {
            m_view.outputPrompt();
            input_move = m_scanner.getInputMove();
        }
        m_state.makeMove(input_move.value());
    }
    m_view.outputWinner();
    menu_context.setExit();
}