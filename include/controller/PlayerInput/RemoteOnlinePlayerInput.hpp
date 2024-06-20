#pragma once
#include "PlayerInput.hpp"
#include <SFML/Network.hpp>
#include <memory>

class RemoteOnlinePlayer : public Player {
private:
    std::shared_ptr<sf::TcpSocket> m_socket;

public:
    RemoteOnlinePlayer(std::shared_ptr<sf::TcpSocket> socket);
    std::string getPrompt() override;
    std::optional<Move> inputMove() override;
};