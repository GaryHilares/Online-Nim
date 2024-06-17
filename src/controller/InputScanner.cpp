#include "../../include/controller/InputScanner.hpp"

InputScanner::InputScanner(std::istream& input_stream)
    : m_input_stream(input_stream)
{
}

std::optional<Move> InputScanner::getInputMove()
{
    int pile_number;
    int num_to_remove;
    if (m_input_stream >> pile_number >> num_to_remove) {
        return Move(pile_number, num_to_remove);
    }
    return std::nullopt;
}
