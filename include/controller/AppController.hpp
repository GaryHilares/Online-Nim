#pragma once
#include "MenuState/MenuContext.hpp"

class AppController {
private:
    MenuContext m_context;

public:
    AppController();
    void run();
};