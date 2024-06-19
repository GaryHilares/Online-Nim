#include "../../../include/controller/MenuStates/JoinMenuState.hpp"
#include "../../../include/controller/MenuContext.hpp"
#include "../../../include/controller/MenuStates/MainMenuState.hpp"
#include <SFML/Network.hpp>

JoinMenuState::JoinMenuState(std::istream& input_stream, std::ostream& output_stream)
    : m_input_stream(input_stream)
    , m_output_stream(output_stream)
{
}

void JoinMenuState::run(MenuContext& context)
{
    constexpr int PORT = 4000;
    std::string address;
    m_output_stream << "Please input IP address of game to join:\n";
    do {
        m_output_stream << "Player> ";
    } while (!(m_input_stream >> address));

    sf::TcpSocket socket;
    if (socket.connect(address, PORT) != sf::Socket::Done) {
        m_output_stream << "Could not connect to given address." << std::endl;
        context.setState(new MainMenuState(m_input_stream, m_output_stream));
    }

    m_output_stream << "Connection established successfully!" << std::endl;
    context.setExit();
}