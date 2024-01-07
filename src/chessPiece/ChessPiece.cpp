#include "ChessPiece.h"
#include "Board.h"

ChessPieceColor ChessPiece::getColor() const {
    return color;
}

std::string ChessPiece::getPosition() const {
    return position;
}

PieceType ChessPiece::getType() const{
    return type;
}

void ChessPiece::setPosition(const std::string &newPosition){
    position = newPosition;
}

std::string ChessPiece::typeToString() const{
    switch (type) {
        case PieceType::Pawn:
            return "Pawn";
        case PieceType::Rook:
            return "Rook";
        case PieceType::Knight:
            return "Knight";
        case PieceType::Bishop:
            return "Bishop";
        case PieceType::Queen:
            return "Queen";
        case PieceType::King:
            return "King";
        default:
            return "Unknown";
    }
}

void ChessPiece::display() const{
    std::cout << typeToString() << " at position " << getPosition()
              << " of color " << (getColor() == ChessPieceColor::White ? "White" : "Black") << std::endl;
}

std::string ChessPiece::typeToSymbol() const {
    switch (type) {
        case PieceType::Pawn:
            return "P";
        case PieceType::Bishop:
            return "B";
        case PieceType::Knight:
            return "N";
        case PieceType::Rook:
            return "R";
        case PieceType::Queen:
            return "Q";
        case PieceType::King:
            return "K";
        default:
            return " ";
    }
}

// do poprawy to poniewaz on uzywa z ChessPiece a nie isMoveValid
bool ChessPiece::isMoveValid(const ChessPiece& piece, const ChessPiece& targetPiece, const ChessBoard& board) const{
    return true;
}


bool Pawn::isMoveValid(const ChessPiece& piece, const ChessPiece& targetPiece, const ChessBoard& board) const {
    int deltaRank = (piece.getColor() == ChessPieceColor::White) ? 1 : -1;

    // Sprawdź, czy ruch pionka jest dozwolony o jedno pole do przodu
    if (targetPiece.getPosition()[1] == piece.getPosition()[1] + deltaRank &&
        targetPiece.getPosition()[0] == piece.getPosition()[0] &&
        (targetPiece.getType() == PieceType::None || targetPiece.getColor() != piece.getColor())) {
        return true;
    }

    // Sprawdź, czy to jest pierwszy ruch pionka o dwa pola do przodu
    if (piece.getPosition()[1] == (piece.getColor() == ChessPieceColor::White) ? '2' : '7' && targetPiece.getPosition()[1] == piece.getPosition()[1] + 2 * deltaRank &&
    targetPiece.getPosition()[0] == piece.getPosition()[0] && targetPiece.getType() == PieceType::None) {
        return true;
    }

    // Sprawdź, czy ruch pionka jest dozwolony do przodu i w ukos
    if (targetPiece.getPosition()[1] == piece.getPosition()[1] + deltaRank &&
        targetPiece.getPosition()[0] == piece.getPosition()[0] + 1 ||
        targetPiece.getPosition()[0] == piece.getPosition()[0] - 1) {
        if (targetPiece.getType() != PieceType::None && targetPiece.getColor() != piece.getColor()) {
            return true;
        }
    }

    // Wszystkie inne przypadki są niepoprawne
    return false;
}

void Pawn::setPosition(const std::string &newPosition) {
    ChessPiece::setPosition(newPosition);
}
