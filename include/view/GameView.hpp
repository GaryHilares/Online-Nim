#pragma once
#include "../controller/PlayerInput/PlayerInput.hpp"
#include <memory>
#include <ostream>

class GameState;

/**
 * @brief Manages the input and output of the main game to the given output stream.
 */
class GameView {
private:
    const GameState& m_game_state;
    std::ostream& m_output_stream;

public:
    /**
     * @brief Creates a new view of the given game_state, sending the output the given output stream.
     * @param game_state Game state to represent in this view.
     * @param output_stream Output stream to which the output of this view will be sent.
     */
    GameView(const GameState& game_state, std::ostream& output_stream);

    /**
     * @brief Outputs a message welcoming the player to the game to the output stream.
     */
    void outputWelcome();

    /**
     * @brief Outputs a string representation of the game state to the output stream.
     */
    void outputGameState();

    /**
     * @brief Outputs a prompt asking for input from the given player input handler.
     * @param player Player input handler whose prompt will be outputted.
     */
    void outputPrompt(const std::unique_ptr<PlayerInput>& player);

    /**
     * @brief Outputs the winner of the game, assuming that it has already ended.
     */
    void outputWinner();
};