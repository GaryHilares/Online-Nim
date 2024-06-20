#pragma once
#include "../../model/GameState.hpp"
#include "../../view/GameView.hpp"
#include "../PlayerInput/PlayerInput.hpp"
#include "MenuState.hpp"
#include <memory>

class GameMenuState : public MenuState {
private:
    GameState m_state;
    std::unique_ptr<PlayerInput> m_player_1;
    std::unique_ptr<PlayerInput> m_player_2;
    GameView m_view;

public:
    GameMenuState(std::ostream& output_stream, std::unique_ptr<PlayerInput> player_1, std::unique_ptr<PlayerInput> player_2);
    void run(MenuContext& menu_context) override;
};
