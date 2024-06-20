#pragma once
#include "PlayerInput.hpp"
#include <istream>

class InputStreamPlayerInput : public PlayerInput {
private:
    std::istream& m_input_stream;

public:
    InputStreamPlayerInput(std::istream& input_stream);
    std::string getPrompt() override;
    std::optional<Move> inputMove() override;
};