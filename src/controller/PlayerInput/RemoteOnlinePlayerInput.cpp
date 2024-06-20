#include "../../../include/controller/PlayerInput/RemoteOnlinePlayerInput.hpp"
#include <iostream>

RemoteOnlinePlayerInput::RemoteOnlinePlayerInput(std::shared_ptr<sf::TcpSocket> socket)
    : m_socket(socket)
{
}

std::string RemoteOnlinePlayerInput::getPrompt()
{
    return "Waiting for remote player to input their move...\n";
}

std::optional<Move> RemoteOnlinePlayerInput::inputMove()
{
    constexpr std::size_t TO_RECEIVE = 2 * sizeof(int);
    int payload[TO_RECEIVE];
    std::size_t received;
    if (m_socket->receive(payload, TO_RECEIVE, received) != sf::Socket::Done || received != TO_RECEIVE) {
        return std::nullopt;
    }
    return Move(payload[0], payload[1]);
}