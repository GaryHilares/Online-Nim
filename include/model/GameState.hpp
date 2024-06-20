#pragma once
#include "Move.hpp"
#include <utility>
#include <vector>

/**
 * @brief Represents a Nim game state.
 */
class GameState {
private:
    std::vector<int> m_piles;
    int m_turn;
    bool m_has_game_ended;
    bool areAllPilesEmpty() const;

public:
    /**
     * @brief Creates a game state representing a new game.
     */
    GameState();

    /**
     * @brief Gets the piles of this game state.
     * @return A constant reference to the piles in the current state of the game.
     */
    const std::vector<int>& getPiles() const;

    /**
     * @brief Gets the number of the turn player in the current game state, or the last player to play if the game has
     *        ended (i.e. the winning player).
     * @return 1 if the first player is to play, 2 otherwise.
     * @details
     */
    int getTurn() const;

    /**
     * @brief Produces whether the given move is legal or not in this game state.
     * @param move The move to be checked.
     * @return True if the given move is legal in this game state, false otherwise.
     */
    bool isLegalMove(Move move) const;

    /**
     * @brief Makes a Nim move in the current game state.
     * @param move Move to be done. Must be a legal move.
     */
    void makeMove(Move move);

    /**
     * @brief Produces whether the game has ended or not.
     * @return True if the game has ended, false otherwise.
     */
    bool hasGameEnded() const;
};
