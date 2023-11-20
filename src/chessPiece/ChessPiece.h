#pragma once
#include <utility>

#include "../../Main.h"

enum class ChessPieceColor{
    White,
    Black
};

enum class PieceType {
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

class ChessPiece {
private:
    ChessPieceColor color;
    std::string position;
    PieceType type;

public:
    ChessPiece(ChessPieceColor color, std::string position, PieceType type)
            : color(color), position(std::move(position)), type(type) {}

    ChessPieceColor getColor() const;
    std::string getPosition() const;
    PieceType getType() const;
};

class Pawn : public ChessPiece {
public:
    using ChessPiece::ChessPiece;

    void display() const  {
        std::cout << "Pawn at position " << getPosition()
                  << " of color " << (getColor() == ChessPieceColor::White ? "White" : "Black") << std::endl;
    }
};