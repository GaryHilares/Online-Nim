#pragma once

class Move {
private:
    int m_pile_number;
    int m_num_to_remove;

public:
    Move(int pile_number, int num_to_remove);
    int getPileNumber() const;
    int getNumToRemove() const;
};