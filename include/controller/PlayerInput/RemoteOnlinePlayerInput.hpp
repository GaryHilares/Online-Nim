#pragma once
#include "PlayerInput.hpp"
#include <SFML/Network.hpp>
#include <memory>

class RemoteOnlinePlayerInput : public PlayerInput {
private:
    std::shared_ptr<sf::TcpSocket> m_socket;

public:
    RemoteOnlinePlayerInput(std::shared_ptr<sf::TcpSocket> socket);
    std::string getPrompt() override;
    std::optional<Move> inputMove() override;
};