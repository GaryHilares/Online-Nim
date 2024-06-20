#pragma once
#include "PlayerInput.hpp"
#include <SFML/Network.hpp>
#include <istream>
#include <memory>

/**
 * @brief Represents an input handler for a player playing in an online game from the current machine.
 */
class LocalOnlinePlayerInput : public PlayerInput {
private:
    std::istream& m_input_stream;
    std::shared_ptr<sf::TcpSocket> m_socket;

public:
    /**
     * @brief Creates a new input handler for a player playing in an online game from the current machine.
     * @param input_stream Input stream to read input from.
     * @param socket TCP socket connected to the computer of the other player.
     */
    LocalOnlinePlayerInput(std::istream& input_stream, std::shared_ptr<sf::TcpSocket> socket);

    /**
     * @brief Produces a string representing a prompt to be asked before taking input.
     * @return A representative prompt asking before taking input.
     */
    std::string getPrompt() override;

    /**
     * @brief Receives input from the input stream, sends it to the other player and produces it as a move.
     * @return The move read from the input stream, or std::nullopt if the read was unsuccessful.
     * @note The legality of the input move in the current game state is not checked.
     */
    std::optional<Move> inputMove() override;
};