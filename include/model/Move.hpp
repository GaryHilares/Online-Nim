#pragma once

/**
 * @brief Represents a move in the Nim game.
 */
class Move {
private:
    int m_pile_number;
    int m_num_to_remove;

public:
    /**
     * @brief Creates a new object representing a Nim move.
     * @param pile_number The number of the pile that will be modified with this move.
     * @param num_to_remove The number of items to remove from the given pile.
     * @note Does not check if the move is legal.
     */
    Move(int pile_number, int num_to_remove);

    /**
     * @brief Gets the pile number to be modified with this move.
     * @return The 0-indexed pile number to be modified with this move.
     */
    int getPileNumber() const;

    /**
     * @brief Gets the number of items that will be removed with this move.
     * @return The number of items that will be removed with this move.
     */
    int getNumToRemove() const;
};