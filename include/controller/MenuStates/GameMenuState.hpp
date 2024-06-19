#pragma once
#include "../../model/GameState.hpp"
#include "../../view/GameView.hpp"
#include "../Player.hpp"
#include "MenuState.hpp"
#include <memory>

class GameMenuState : public MenuState {
private:
    GameState m_state;
    std::unique_ptr<Player> m_player_1;
    std::unique_ptr<Player> m_player_2;
    GameView m_view;

public:
    GameMenuState(std::ostream& output_stream, Player* player_1, Player* player_2);
    void run(MenuContext& menu_context) override;
};
