#pragma once
#include "PlayerInput.hpp"
#include <istream>

/**
 * @brief Represents a player input handler that reads input from an input stream.
 */
class InputStreamPlayerInput : public PlayerInput {
private:
    std::istream& m_input_stream;

public:
    /**
     * @brief Creates a new player input handler that reads input from the given input stream.
     * @param input_stream Input stream to read input from.
     */
    InputStreamPlayerInput(std::istream& input_stream);

    /**
     * @brief Produces a string representing a prompt to be asked before taking input.
     * @return A representative prompt asking before taking input.
     */
    std::string getPrompt() override;

    /**
     * @brief Reads input from the input stream as a move.
     * @return The move read from the input stream, or std::nullopt if the read was unsuccessful.
     * @note The legality of the input move in the current game state is not checked.
     */
    std::optional<Move> inputMove() override;
};