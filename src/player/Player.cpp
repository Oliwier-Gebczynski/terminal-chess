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


