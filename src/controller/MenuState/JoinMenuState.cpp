#include "../../../include/controller/MenuState/JoinMenuState.hpp"
#include "../../../include/controller/MenuState/GameMenuState.hpp"
#include "../../../include/controller/MenuState/MainMenuState.hpp"
#include "../../../include/controller/MenuState/MenuContext.hpp"
#include "../../../include/controller/PlayerInput/LocalOnlinePlayerInput.hpp"
#include "../../../include/controller/PlayerInput/RemoteOnlinePlayerInput.hpp"
#include <SFML/Network.hpp>
#include <memory>

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

    std::shared_ptr<sf::TcpSocket> client = std::make_shared<sf::TcpSocket>();
    if (client->connect(address, PORT) != sf::Socket::Done) {
        m_output_stream << "Could not connect to given address." << std::endl;
        context.setState(std::make_unique<MainMenuState>(m_input_stream, m_output_stream));
    } else {
        m_output_stream << "Connection established successfully!" << std::endl;
        context.setState(std::make_unique<GameMenuState>(m_output_stream,
            std::make_unique<RemoteOnlinePlayerInput>(client),
            std::make_unique<LocalOnlinePlayerInput>(m_input_stream, client)));
    }
}