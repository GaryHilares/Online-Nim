#include "../../../include/controller/MenuStates/HostMenuState.hpp"
#include "../../../include/controller/MenuContext.hpp"
#include "../../../include/controller/MenuStates/MainMenuState.hpp"

HostMenuState::HostMenuState(std::istream& input_stream, std::ostream& output_stream)
    : m_input_stream(input_stream)
    , m_output_stream(output_stream)
{
}

void HostMenuState::run(MenuContext& context)
{
    constexpr int PORT = 4000;
    m_output_stream << "Waiting for incoming connection..." << std::endl;
    if (m_listener.listen(PORT) != sf::Socket::Done) {
        m_output_stream << "Could not listen to port " << PORT << "." << std::endl;
        context.setState(new MainMenuState(m_input_stream, m_output_stream));
    }

    sf::TcpSocket client;
    if (m_listener.accept(client) != sf::Socket::Done) {
        m_output_stream << "Could not establish a connection." << std::endl;
        context.setState(new MainMenuState(m_input_stream, m_output_stream));
    }

    m_output_stream << "Established a connection successfully!" << std::endl;
    context.setExit();
}