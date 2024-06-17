#pragma once
#include "../model/Move.hpp"
#include <istream>
#include <utility>

class InputScanner {
private:
    std::istream& m_input_stream;
public:
    InputScanner(std::istream& input_stream);
    Move getInputMove();
};