#pragma once
#include "PlayerInput.hpp"
#include <SFML/Network.hpp>
#include <memory>

/**
 * @brief Represents an input handler for a player playing in an online game from a remote machine.
 */
class RemoteOnlinePlayerInput : public PlayerInput {
private:
    std::shared_ptr<sf::TcpSocket> m_socket;

public:
    /**
     * @brief Creates a new input handler for a player playing in an online game from the remote machine.
     * @param socket TCP socket connected to the computer of the player.
     */
    RemoteOnlinePlayerInput(std::shared_ptr<sf::TcpSocket> socket);

    /**
     * @brief Produces a string representing a prompt to be asked before waiting for input from the other player.
     * @return A representative prompt to be asked before waiting for input from the other player.
     */
    std::string getPrompt() override;

    /**
     * @brief Waits until there is input in the socket, and then reads it as a move.
     * @return The move read from TCP socket, or std::nullopt if the read was unsuccessful.
     * @note The legality of the input move in the current game state is not checked.
     */
    std::optional<Move> inputMove() override;
};