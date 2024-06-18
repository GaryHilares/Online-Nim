#include "../../include/controller/AppController.hpp"
#include "../../include/controller/GameController.hpp"
#include <iostream>

AppController::AppController()
    : m_context(new GameController(std::cin, std::cout))
{
}

void AppController::run()
{
    while (!m_context.shouldExit()) {
        m_context.requestRun();
    }
}