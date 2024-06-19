#pragma once
#include "../model/Move.hpp"
#include <optional>
#include <string>

class Player {
public:
    virtual std::string getPrompt() = 0;
    virtual std::optional<Move> inputMove() = 0;
    virtual ~Player() = default;
};