#pragma once
#include "MenuState.hpp"
#include <istream>
#include <ostream>

/**
 * @brief Represents the state where a player is trying to join an online game.
 */
class JoinMenuState : public MenuState {
private:
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    /**
     * @brief Creates a new state representing the player joining a game hosted online.
     * @param input_stream Input stream from which text input of the game will be read.
     * @param output_stream Output stream to which the text output of the game will be sent.
     */
    JoinMenuState(std::istream& input_stream, std::ostream& output_stream);

    /**
     * @brief Asks the user for an address input and tries to join a game run at the given IP address.
     * @param menu_context Context handling the menu state.
     */
    void run(MenuContext& context) override;
};