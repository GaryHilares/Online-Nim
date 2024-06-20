#pragma once
#include "MenuState.hpp"
#include <memory>

class MenuContext {
private:
    std::unique_ptr<MenuState> m_state;
    bool m_should_exit;

public:
    MenuContext(std::unique_ptr<MenuState> state);
    void setState(std::unique_ptr<MenuState> state);
    void requestRun();
    void setExit();
    bool shouldExit() const;
};