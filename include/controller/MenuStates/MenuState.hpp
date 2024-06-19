#pragma once

class MenuContext;

class MenuState {
public:
    virtual void run(MenuContext& context) = 0;
    virtual ~MenuState() = default;
};
