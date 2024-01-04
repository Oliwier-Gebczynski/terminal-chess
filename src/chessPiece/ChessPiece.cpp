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

bool ChessPiece::isMoveValid(const ChessPiece& piece, const ChessPiece& targetPiece, const ChessBoard& board) const{
    return false;
}


bool Pawn::isMoveValid(const ChessPiece &piece, const ChessPiece &targetPiece, const ChessBoard &board) const {
    // Sprawdź, czy ruch pionka jest dozwolony
    int deltaRank = (piece.getColor() == ChessPieceColor::White) ? 1 : -1;

    // Sprawdź, czy ruch do przodu jest o jedno lub dwa pola
    if ((targetPiece.getPosition()[1] == piece.getPosition()[1] + deltaRank &&
         targetPiece.getPosition()[0] == piece.getPosition()[0]) ||
        ((piece.getPosition()[1] == '2' && piece.getColor() == ChessPieceColor::White) ||
         (piece.getPosition()[1] == '7' && piece.getColor() == ChessPieceColor::Black)) &&
        targetPiece.getPosition()[1] == piece.getPosition()[1] + 2 * deltaRank &&
        targetPiece.getPosition()[0] == piece.getPosition()[0]) {

        // Sprawdź, czy docelowe pole jest puste
        if (targetPiece.getType() == PieceType::None) {
            return true;
        }
    }

    // Sprawdź, czy to pole docelowe to przekątne bicie
    if (std::abs(targetPiece.getPosition()[0] - piece.getPosition()[0]) == 1 &&
        targetPiece.getPosition()[1] == piece.getPosition()[1] + deltaRank &&
        targetPiece.getType() != PieceType::None &&
        targetPiece.getColor() != piece.getColor()) {
        return true;
    }

    // Wszystkie inne przypadki są niepoprawne
    return false;
}

void Pawn::setPosition(const std::string &newPosition) {
    ChessPiece::setPosition(newPosition);
}
