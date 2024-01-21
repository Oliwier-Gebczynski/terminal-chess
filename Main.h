#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <optional>
#include <cmath>
#include <cstdlib>

/**
 * @enum ChessPieceColor
 * @brief Enumerates the possible colors of chess pieces.
 */
enum class ChessPieceColor{
    White,
    Black,
    None
};

/**
 * @enum PieceType
 * @brief Enumerates the possible types of chess pieces.
 */
enum class PieceType {
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King,
    None
};

/**
 * @class Player
 * @brief Represents a player in the chess game.
 */
class Player;

/**
 * @class ChessBoard
 * @brief Represents the chess board and game state.
 */
class ChessBoard;




