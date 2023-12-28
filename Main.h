#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <memory>
#include <algorithm>
#include <iomanip>

enum class ChessPieceColor{
    White,
    Black,
    None
};

enum class PieceType {
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King,
    None
};

class Player;

class ChessBoard;




