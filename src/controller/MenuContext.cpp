#include "../../include/controller/MenuContext.hpp"

MenuContext::MenuContext(MenuState* state)
    : m_state(state)
    , m_should_exit(false)
{
}

void MenuContext::setState(MenuState* state)
{
    m_state.reset(state);
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