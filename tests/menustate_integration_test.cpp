#include "../include/controller/MenuState/MainMenuState.hpp"
#include "../include/controller/MenuState/MenuContext.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(MenuStateIntegrationTest, OfflineGame)
{
    std::ostringstream fake_ostream;
    std::istringstream fake_istream("1 0 50 1 50 2 50 3 50 4 50");
    MenuContext context(std::make_unique<MainMenuState>(fake_istream, fake_ostream));
    for (int i = 0; i < 2; i++) {
        context.requestRun();
    }
    std::string contents = fake_ostream.str();
    ASSERT_NE(contents.find("Player 1 won the game"), std::string::npos);
    ASSERT_TRUE(context.shouldExit());
}
