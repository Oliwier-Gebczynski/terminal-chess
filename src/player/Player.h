#pragma once
#include "../../Main.h"

class Player {
private:
    ChessPieceColor playerColor_;

public:
    Player(ChessPieceColor playerColor) : playerColor_(playerColor) {}

    ChessPieceColor getColor();
};