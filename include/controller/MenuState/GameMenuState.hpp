#pragma once
#include "../../model/GameState.hpp"
#include "../../view/GameView.hpp"
#include "../PlayerInput/PlayerInput.hpp"
#include "MenuState.hpp"
#include <memory>

/**
 * @brief Represents the state when the game menu is being presented to the user.
 */
class GameMenuState : public MenuState {
private:
    GameState m_state;
    std::unique_ptr<PlayerInput> m_player_1;
    std::unique_ptr<PlayerInput> m_player_2;
    GameView m_view;

public:
    /**
     * @brief Creates a state representing a new Nim game between player_1 and player_2.
     * @param output_stream Output stream to which the text output of the game will be sent.
     * @param player_1 First player to play on the Nim game.
     * @param player_2 Second player to play on the Nim game.
     */
    GameMenuState(std::ostream& output_stream, std::unique_ptr<PlayerInput> player_1,
        std::unique_ptr<PlayerInput> player_2);

    /**
     * @brief Runs the game contained by this state.
     * @param menu_context Context handling the menu state.
     */
    void run(MenuContext& menu_context) override;
};
