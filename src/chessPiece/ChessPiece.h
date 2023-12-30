#pragma once

#include "../../Main.h"

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

    std::string typeToString() const;
    std::string typeToSymbol() const;
    void display() const;


    ~ChessPiece() = default;
};

class Pawn : public ChessPiece {
public:
    Pawn(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::Pawn) {}

            bool isMoveValid(const std::string& to) const {
                int fromFile = getPosition()[0] - 'A';
                int fromRank = getPosition()[1] - '1';
                int toFile = to[0] - 'A';
                int toRank = to[1] - '1';

                if (getColor() == ChessPieceColor::White) {
                    return (toRank == fromRank + 1) && (toFile == fromFile);
                } else {
                    return (toRank == fromRank - 1) && (toFile == fromFile);
                }
    }
};

class Bishop : public ChessPiece{
public:
    Bishop(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::Bishop) {}
};

class Knight : public ChessPiece{
public:
    Knight(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::Knight) {}
};

class Rook : public ChessPiece{
public:
    Rook(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::Rook) {}
};

class Queen : public ChessPiece{
public:
    Queen(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::Queen) {}
};

class King : public ChessPiece{
public:
    King(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::King) {}
};

class EmptyPiece : public ChessPiece {
public:
    EmptyPiece()
            : ChessPiece(ChessPieceColor::None, "", PieceType::None) {}
};




