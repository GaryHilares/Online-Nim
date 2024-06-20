#pragma once
#include "MenuState.hpp"
#include <SFML/Network.hpp>
#include <istream>
#include <ostream>

/**
 * @brief Represents the state where a player is hosting an online game and is waiting for a connection.
 */
class HostMenuState : public MenuState {
private:
    sf::TcpListener m_listener;
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    /**
     * @brief Creates a new state representing the player awaiting a connection.
     * @param input_stream Input stream from which text input of the game will be read.
     * @param output_stream Output stream to which the text output of the game will be sent.
     */
    HostMenuState(std::istream& input_stream, std::ostream& output_stream);

    /**
     * @brief Starts hosting a game and waits for another player to join.
     * @param menu_context Context handling the menu state.
     */
    void run(MenuContext& context) override;
};