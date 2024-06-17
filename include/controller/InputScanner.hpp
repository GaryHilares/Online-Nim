#pragma once
#include "../model/Move.hpp"
#include <istream>
#include <optional>
#include <utility>

class InputScanner {
private:
    std::istream& m_input_stream;

public:
    InputScanner(std::istream& input_stream);
    std::optional<Move> getInputMove();
};