#pragma once

#include "../../Main.h"

class Player {
private:
    ChessPieceColor playerColor_;
    std::vector<ChessPiece> pieces_;

public:
    Player(ChessPieceColor playerColor) : playerColor_(playerColor) {}

    void addPiece(const ChessPiece& piece);
    void removePiece(const std::string& position);

    const std::vector<ChessPiece>& getPieces() const;

    void startPosition(ChessPieceColor color);
};

class BlackPlayer : public Player {
public:
    BlackPlayer() : Player(ChessPieceColor::Black) {}
};

class WhitePlayer : public Player {
public:
    WhitePlayer() : Player(ChessPieceColor::White) {}
};