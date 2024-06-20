#include "../../../include/controller/PlayerInput/InputStreamPlayerInput.hpp"

InputStreamPlayerInput::InputStreamPlayerInput(std::istream& input_stream)
    : m_input_stream(input_stream)
{
}

std::string InputStreamPlayerInput::getPrompt()
{
    return "Player> ";
}

std::optional<Move> InputStreamPlayerInput::inputMove()
{
    int pile_number;
    int num_to_remove;
    if (!(m_input_stream >> pile_number >> num_to_remove)) {
        return std::nullopt;
    }
    return Move(pile_number, num_to_remove);
}