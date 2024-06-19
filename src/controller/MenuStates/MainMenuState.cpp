#include "../../../include/controller/MenuStates/MainMenuState.hpp"
#include "../../../include/controller/MenuContext.hpp"
#include "../../../include/controller/MenuStates/GameMenuState.hpp"
#include "../../../include/controller/MenuStates/HostMenuState.hpp"
#include "../../../include/controller/MenuStates/JoinMenuState.hpp"
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
        context.setState(new GameMenuState(m_input_stream, m_output_stream));
    }
    if (choice == 2) {
        context.setState(new HostMenuState(m_input_stream, m_output_stream));
    } else {
        context.setState(new JoinMenuState(m_input_stream, m_output_stream));
    }
}