#include "../../include/controller/AppController.hpp"
#include "../../include/controller/MainMenuState.hpp"
#include <iostream>

AppController::AppController()
    : m_context(new MainMenuState(std::cin, std::cout))
{
}

void AppController::run()
{
    while (!m_context.shouldExit()) {
        m_context.requestRun();
    }
}