#include "../../../include/controller/PlayerInput/InputStreamPlayerInput.hpp"

LocalStreamPlayer::LocalStreamPlayer(std::istream& input_stream)
    : m_input_stream(input_stream)
{
}

std::string LocalStreamPlayer::getPrompt()
{
    return "Player> ";
}

std::optional<Move> LocalStreamPlayer::inputMove()
{
    int pile_number;
    int num_to_remove;
    if (!(m_input_stream >> pile_number >> num_to_remove)) {
        return std::nullopt;
    }
    return Move(pile_number, num_to_remove);
}