#include "../../include/controller/MainMenuState.hpp"
#include "../../include/controller/GameController.hpp"
#include "../../include/controller/MenuContext.hpp"
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
        context.setState(new GameController(m_input_stream, m_output_stream));
    } else {
        m_output_stream << "Not implemented." << std::endl;
        context.setExit();
    }
}