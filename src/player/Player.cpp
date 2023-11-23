#include "Player.h"
#include "../chessPiece/ChessPiece.h"

void Player::addPiece(const ChessPiece &piece) {
    pieces_.push_back(piece);
}

void Player::removePiece(const std::string &position) {
    pieces_.erase(std::remove_if(pieces_.begin(), pieces_.end(),
                                 [&position](const ChessPiece& piece) {
                                     return piece.getPosition() == position;
                                 }), pieces_.end());
}

const std::vector<ChessPiece> &Player::getPieces() const {
    return pieces_;
}

void Player::startPosition(ChessPieceColor color) {
    for (char file = 'A'; file <= 'H'; file++) {
        std::string position;
        if (color == ChessPieceColor::Black) {
            position = std::string(1, file) + "7";
            pieces_.emplace_back(color, position, PieceType::Pawn);
        } else if (color == ChessPieceColor::White) {
            position = std::string(1, file) + "2";
            pieces_.emplace_back(color, position, PieceType::Pawn);
        }
    }

    std::string backRank = (color == ChessPieceColor::Black) ? "8" : "1";
    pieces_.emplace_back(color, "A" + backRank, PieceType::Rook);
    pieces_.emplace_back(color, "B" + backRank, PieceType::Knight);
    pieces_.emplace_back(color, "C" + backRank, PieceType::Bishop);
    pieces_.emplace_back(color, "D" + backRank, PieceType::Queen);
    pieces_.emplace_back(color, "E" + backRank, PieceType::King);
    pieces_.emplace_back(color, "F" + backRank, PieceType::Bishop);
    pieces_.emplace_back(color, "G" + backRank, PieceType::Knight);
    pieces_.emplace_back(color, "H" + backRank, PieceType::Rook);
}

