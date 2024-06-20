#include "../../../include/controller/MenuState/MainMenuState.hpp"
#include "../../../include/controller/MenuState/GameMenuState.hpp"
#include "../../../include/controller/MenuState/HostMenuState.hpp"
#include "../../../include/controller/MenuState/JoinMenuState.hpp"
#include "../../../include/controller/MenuState/MenuContext.hpp"
#include "../../../include/controller/PlayerInput/InputStreamPlayerInput.hpp"
#include <string>

MainMenuState::MainMenuState(std::istream& input_stream, std::ostream& output_stream)
    : m_input_stream(input_stream)
    , m_output_stream(output_stream)
{
}

void MainMenuState::run(MenuContext& context)
{
    m_output_stream << "Welcome to Online-Nim! Please select an option:\n"
                    << "1. Play offline\n"
                    << "2. Host online game\n"
                    << "3. Join online game\n"
                    << std::flush;
    int choice;
    do {
        m_output_stream << "Player> ";
    } while (!(m_input_stream >> choice && choice <= 3 && choice >= 1));
    if (choice == 1) {
        context.setState(std::make_unique<GameMenuState>(m_output_stream,
            std::make_unique<LocalStreamPlayer>(m_input_stream),
            std::make_unique<LocalStreamPlayer>(m_input_stream)));
    } else if (choice == 2) {
        context.setState(std::make_unique<HostMenuState>(m_input_stream, m_output_stream));
    } else {
        context.setState(std::make_unique<JoinMenuState>(m_input_stream, m_output_stream));
    }
}