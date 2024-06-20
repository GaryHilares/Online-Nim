#include "../../../include/controller/MenuState/MenuContext.hpp"

MenuContext::MenuContext(std::unique_ptr<MenuState> state)
    : m_state(std::move(state))
    , m_should_exit(false)
{
}

void MenuContext::setState(std::unique_ptr<MenuState> state)
{
    m_state = std::move(state);
}

void MenuContext::requestRun()
{
    return m_state->run(*this);
}

void MenuContext::setExit()
{
    m_should_exit = true;
}

bool MenuContext::shouldExit() const
{
    return m_should_exit;
}