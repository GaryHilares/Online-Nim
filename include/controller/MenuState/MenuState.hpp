#pragma once

class MenuContext;

/**
 * @brief Interface for menu states to be handled by the menu context.
 */
class MenuState {
public:
    /**
     * @brief Runs the menu that this state represents.
     * @param context Context handling this menu state.
     */
    virtual void run(MenuContext& context) = 0;

    // Required for runtime polymorphism.
    virtual ~MenuState() = default;
};
