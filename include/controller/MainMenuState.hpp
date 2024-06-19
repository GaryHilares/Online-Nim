#pragma once
#include "MenuState.hpp"
#include <istream>
#include <ostream>

class MainMenuState : public MenuState {
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    MainMenuState(std::istream& input_stream, std::ostream& output_stream);
    void run(MenuContext& context) override;
};