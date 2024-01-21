#pragma once
#include "../../Main.h"

/**
 * @class Player
 * @brief Represents a player in the chess game.
 */
class Player {
private:
    ChessPieceColor playerColor_;

public:
    /**
     * @brief Constructor for the Player class.
     * @param playerColor The color of the player's chess pieces.
     */
    Player(ChessPieceColor playerColor) : playerColor_(playerColor) {}

    /**
     * @brief Gets the color of the player's chess pieces.
     * @return The color of the player's chess pieces (ChessPieceColor::White or ChessPieceColor::Black).
     */
    ChessPieceColor getColor();
};