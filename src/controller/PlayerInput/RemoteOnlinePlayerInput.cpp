#include "../../../include/controller/PlayerInput/RemoteOnlinePlayerInput.hpp"
#include <iostream>

RemoteOnlinePlayer::RemoteOnlinePlayer(std::shared_ptr<sf::TcpSocket> socket)
    : m_socket(socket)
{
}

std::string RemoteOnlinePlayer::getPrompt()
{
    return "Waiting for remote player to input their move...\n";
}

std::optional<Move> RemoteOnlinePlayer::inputMove()
{
    constexpr std::size_t TO_RECEIVE = 2 * sizeof(int);
    int payload[TO_RECEIVE];
    std::size_t received;
    if (m_socket->receive(payload, TO_RECEIVE, received) != sf::Socket::Done || received != TO_RECEIVE) {
        return std::nullopt;
    }
    return Move(payload[0], payload[1]);
}