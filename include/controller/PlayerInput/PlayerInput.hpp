#pragma once
#include "../../model/Move.hpp"
#include <optional>
#include <string>

/**
 * @brief Interface for methods of receiving user input.
 */
class PlayerInput {
public:
    /**
     * @brief Produces a string representing a prompt to be asked before taking input.
     * @return A representative prompt asking before taking input.
     */
    virtual std::string getPrompt() = 0;

    /**
     * @brief Reads a move from an implementation-specific input source.
     * @return A move if the input read was successful, std::nullopt otherwise.
     * @note The legality of the input move in the current game state is not checked.
     */
    virtual std::optional<Move> inputMove() = 0;

    // Required for runtime polymorphism
    virtual ~PlayerInput() = default;
};