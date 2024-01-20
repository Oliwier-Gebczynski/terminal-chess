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
    if(piece.getType() == PieceType::Pawn){
        int deltaRank = (piece.getColor() == ChessPieceColor::White) ? 1 : -1;

        std::cout << "Dziala ta funkcja" << std::endl;

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
    } else if (getType() == PieceType::Rook) {
        // W tym przypadku, dla wieży, sprawdź ruch w pionie lub poziomie, ale nie oba jednocześnie
        int fromFile = piece.getPosition()[0];
        int fromRank = piece.getPosition()[1];
        int toFile = targetPiece.getPosition()[0];
        int toRank = targetPiece.getPosition()[1];

        if (((fromFile == toFile && fromRank != toRank) || (fromRank == toRank && fromFile != toFile)) && (targetPiece.getType() != PieceType::King)) {
            return board.isStraightMoveValid(piece.getPosition(), targetPiece.getPosition());
        } else {
            return false;
        }
    } else if (getType() == PieceType::Bishop) {
        // Check for valid bishop moves
        int fromFile = piece.getPosition()[0];
        int fromRank = piece.getPosition()[1];
        int toFile = targetPiece.getPosition()[0];
        int toRank = targetPiece.getPosition()[1];

        if ((std::abs(toFile - fromFile) == std::abs(toRank - fromRank)) && (targetPiece.getType() != PieceType::King)) {
            return board.isDiagonalMoveValid(piece.getPosition(), targetPiece.getPosition());
        } else {
            // Invalid bishop move
            return false;
        }
    } else if (getType() == PieceType::Queen) {
        // Dla królowej, sprawdź zarówno prosty, jak i ukosny ruch, ale bez mieszania ich
        return board.isStraightMoveValid(piece.getPosition(), targetPiece.getPosition()) ||
               board.isDiagonalMoveValid(piece.getPosition(), targetPiece.getPosition());
    } else if (getType() == PieceType::Knight) {
        // Ruch koniem
        int fileDiff = std::abs(targetPiece.getPosition()[0] - piece.getPosition()[0]);
        int rankDiff = std::abs(targetPiece.getPosition()[1] - piece.getPosition()[1]);

        return ((fileDiff == 2 && rankDiff == 1) || (fileDiff == 1 && rankDiff == 2)) &&
                                                   (targetPiece.getType() != PieceType::King) && // Dodatkowy warunek - nie możemy zbić króla
                                                   ((targetPiece.getType() == PieceType::None || targetPiece.getColor() != piece.getColor()));
    }

    return false;
}