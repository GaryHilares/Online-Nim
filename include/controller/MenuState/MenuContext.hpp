#pragma once
#include "MenuState.hpp"
#include <memory>

/**
 * @brief Represents the context which handles the different states of the menu.
 */
class MenuContext {
private:
    std::unique_ptr<MenuState> m_state;
    bool m_should_exit;

public:
    /**
     * @brief Creates a new context with the given initial state.
     * @param state Initial state to be assigned to this context.
     */
    MenuContext(std::unique_ptr<MenuState> state);

    /**
     * @brief Sets the state of this context to the given state.
     * @param state State to be set to this context.
     */
    void setState(std::unique_ptr<MenuState> state);

    /**
     * @brief Runs the state contained in this context.
     */
    void requestRun();

    /**
     * @brief Sets a flag that indicates that this context should stop being requested to run.
     */
    void setExit();

    /**
     * @brief Produces whether this context should stop being requested to run.
     * @return True if the context should stop being requested to run, false otherwise.
     */
    bool shouldExit() const;
};