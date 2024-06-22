#include "../../../include/controller/PlayerInput/RemoteOnlinePlayerInput.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>

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
    constexpr std::size_t BYTES_TO_RECEIVE = 2 * sizeof(int);
    int buffer[BYTES_TO_RECEIVE];
    std::size_t received;
    switch (m_socket->receive(buffer, BYTES_TO_RECEIVE, received)) {
    case sf::Socket::Done:
        assert(received == BYTES_TO_RECEIVE);
        return Move(buffer[0], buffer[1]);
    case sf::Socket::Disconnected:
    case sf::Socket::Error:
        throw std::runtime_error("Socket could not receive move successfully.");
    default:
        return std::nullopt;
    }
}