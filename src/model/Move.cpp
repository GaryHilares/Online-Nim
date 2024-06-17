#include "../../include/model/Move.hpp"

Move::Move(int pile_number, int num_to_remove)
    : m_pile_number(pile_number)
    , m_num_to_remove(num_to_remove)
{
}

int Move::getPileNumber() const
{
    return m_pile_number;
}

int Move::getNumToRemove() const
{
    return m_num_to_remove;
}
