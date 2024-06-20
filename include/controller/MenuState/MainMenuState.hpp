#pragma once
#include "MenuState.hpp"
#include <istream>
#include <ostream>

/**
 * @brief Represents the state where the main menu is being displayed.
 */
class MainMenuState : public MenuState {
private:
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    /**
     * @brief Creates a new state representing the main menu of the game.
     * @param input_stream Input stream from which text input of the game will be read.
     * @param output_stream Output stream to which the text output of the game will be sent.
     */
    MainMenuState(std::istream& input_stream, std::ostream& output_stream);

    /**
     * @brief Disṕlays the main menu options and allows the user to interact with it.
     * @param menu_context Context handling the menu state.
     */
    void run(MenuContext& context) override;
};