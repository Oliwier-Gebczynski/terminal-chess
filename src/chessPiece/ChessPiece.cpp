#include "ChessPiece.h"

ChessPieceColor ChessPiece::getColor() const {
    return color;
}

std::string ChessPiece::getPosition() const {
    return position;
}

PieceType ChessPiece::getType() const{
    return type;
}