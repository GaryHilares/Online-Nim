#pragma once
#include "PlayerInput.hpp"
#include <istream>

class LocalStreamPlayer : public Player {
private:
    std::istream& m_input_stream;

public:
    LocalStreamPlayer(std::istream& input_stream);
    std::string getPrompt() override;
    std::optional<Move> inputMove() override;
};