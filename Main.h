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




