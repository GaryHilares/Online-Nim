#include "../include/controller/GameController.hpp"
#include <iostream>

int main()
{
    GameController game_controller(std::cin, std::cout);
    game_controller.run();
}