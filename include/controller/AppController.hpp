#pragma once
#include "MenuState/MenuContext.hpp"

/**
 * @brief Represents the controller for the main application.
 */
class AppController {
private:
    MenuContext m_context;

public:
    /**
     * @brief Creates a new controller for the application, which initially displays the main menu.
     * @details Reads and writes to the standard I/O (using std::cin and std::cout).
     */
    AppController();

    /**
     * @brief Runs the application.
     */
    void run();
};