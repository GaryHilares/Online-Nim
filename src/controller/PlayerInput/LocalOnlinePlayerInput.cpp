#include "../../../include/controller/PlayerInput/LocalOnlinePlayerInput.hpp"
#include <cassert>
#include <stdexcept>

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
    // Read move from input stream
    int pile_number;
    int num_to_remove;
    if (!(m_input_stream >> pile_number >> num_to_remove)) {
        return std::nullopt;
    }

    // Send to the other player
    constexpr std::size_t BYTES_TO_SEND = 2 * sizeof(int);
    int buffer[BYTES_TO_SEND] = { pile_number, num_to_remove };
    std::size_t received;
    switch (m_socket->send(buffer, BYTES_TO_SEND, received)) {
    case sf::Socket::Done:
        assert(received == BYTES_TO_SEND);
        return Move(pile_number, num_to_remove);
    case sf::Socket::Disconnected:
    case sf::Socket::Error:
        throw std::runtime_error("Socket could not send move successfully.");
    default:
        return std::nullopt;
    }
}