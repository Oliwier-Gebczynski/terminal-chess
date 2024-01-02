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

bool ChessPiece::isMoveValid(const ChessPiece& piece, const std::string& to, const ChessBoard& board) const{

    if(piece.getType() == PieceType::Pawn){
        int rankDiff = std::abs(to[1] - getPosition()[1]);
        int fileDiff = std::abs(to[0] - getPosition()[0]);

        if (getColor() == ChessPieceColor::White) { // Białe pionki poruszają się do góry planszy (rosnący numer wiersza)
            if (rankDiff == 1 && fileDiff == 0) {
                return true;
            } else if (rankDiff == 2 && fileDiff == 0 && getPosition()[1] == '2') {
                return true;
            } else if (rankDiff == 1 && fileDiff == 1) {
                const ChessPiece& targetPiece = board.getChessPieceAt(to);
                return targetPiece.getColor() == ChessPieceColor::Black;
            }
        }

        else if (getColor() == ChessPieceColor::Black) { // Czarne pionki poruszają się w dół planszy (malejący numer wiersza)
            if (rankDiff == 1 && fileDiff == 0) {
                return true;
            } else if (rankDiff == 2 && fileDiff == 0 && getPosition()[1] == '7') {
                return true;
            } else if (rankDiff == 1 && fileDiff == 1) {
                const ChessPiece& targetPiece = board.getChessPieceAt(to);
                return targetPiece.getColor() == ChessPieceColor::White;
            }
        }
    }


    return false;
}


