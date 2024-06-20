#include "../../include/controller/AppController.hpp"
#include "../../include/controller/MenuState/MainMenuState.hpp"
#include <iostream>

AppController::AppController()
    : m_context(std::make_unique<MainMenuState>(std::cin, std::cout))
{
}

void AppController::run()
{
    while (!m_context.shouldExit()) {
        m_context.requestRun();
    }
}