#pragma once
#include "MenuState.hpp"
#include <istream>
#include <ostream>

class JoinMenuState : public MenuState {
private:
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    JoinMenuState(std::istream& input_stream, std::ostream& output_stream);
    void run(MenuContext& context) override;
};