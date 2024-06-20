#include "../../../include/controller/PlayerInput/LocalOnlinePlayerInput.hpp"

LocalOnlinePlayerInput::LocalOnlinePlayerInput(std::istream& input_stream, std::shared_ptr<sf::TcpSocket> socket)
    : m_input_stream(input_stream)
    , m_socket(socket)
{
}

std::string LocalOnlinePlayerInput::getPrompt()
{
    return "Player> ";
}

std::optional<Move> LocalOnlinePlayerInput::inputMove()
{
    int pile_number;
    int num_to_remove;
    if (!(m_input_stream >> pile_number >> num_to_remove)) {
        return std::nullopt;
    }
    constexpr std::size_t TO_SEND = 2 * sizeof(int);
    int payload[TO_SEND] = { pile_number, num_to_remove };
    m_socket->send(payload, TO_SEND);
    return Move(pile_number, num_to_remove);
}