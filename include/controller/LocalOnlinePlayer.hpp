#pragma once
#include "Player.hpp"
#include <SFML/Network.hpp>
#include <istream>
#include <memory>

class LocalOnlinePlayer : public Player {
private:
    std::istream& m_input_stream;
    std::shared_ptr<sf::TcpSocket> m_socket;

public:
    LocalOnlinePlayer(std::istream& input_stream, std::shared_ptr<sf::TcpSocket> socket);
    std::string getPrompt() override;
    std::optional<Move> inputMove() override;
};