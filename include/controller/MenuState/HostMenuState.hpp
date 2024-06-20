#pragma once
#include "MenuState.hpp"
#include <SFML/Network.hpp>
#include <istream>
#include <ostream>

class HostMenuState : public MenuState {
private:
    sf::TcpListener m_listener;
    std::istream& m_input_stream;
    std::ostream& m_output_stream;

public:
    HostMenuState(std::istream& input_stream, std::ostream& output_stream);
    void run(MenuContext& context) override;
};