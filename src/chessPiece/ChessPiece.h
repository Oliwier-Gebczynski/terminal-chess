#pragma once

#include "../../Main.h"

/**
 * @class ChessPiece
 * @brief Represents a generic chess piece with color, position, and type.
 */
class ChessPiece {
private:
    ChessPieceColor color;
    std::string position;
    PieceType type;

public:
public:
    /**
     * @brief Constructor for ChessPiece class.
     * @param color The color of the chess piece.
     * @param position The initial position of the chess piece.
     * @param type The type of the chess piece.
     */
    ChessPiece(ChessPieceColor color, std::string position, PieceType type)
            : color(color), position(std::move(position)), type(type) {}

    /**
     * @brief Gets the color of the chess piece.
     * @return The color of the chess piece.
     */
    ChessPieceColor getColor() const;

    /**
     * @brief Gets the position of the chess piece.
     * @return The position of the chess piece.
     */
    std::string getPosition() const;

    /**
     * @brief Gets the type of the chess piece.
     * @return The type of the chess piece.
     */
    PieceType getType() const;

    /**
     * @brief Converts the piece type to a string representation.
     * @return String representation of the piece type.
     */
    std::string typeToString() const;

    /**
     * @brief Converts the piece type to its symbol.
     * @return Symbol representing the piece type.
     */
    std::string typeToSymbol() const;

    /**
     * @brief Displays information about the chess piece.
     */
    void display() const;

    /**
     * @brief Sets the position of the chess piece.
     * @param newPosition The new position of the chess piece.
     */
    void setPosition(const std::string& newPosition);

    /**
     * @brief Checks if a move is valid for the chess piece.
     * @param piece The target chess piece to move to.
     * @param targetPiece The target chess piece at the destination.
     * @param board The chess board.
     * @return True if the move is valid, false otherwise.
     */
    bool isMoveValid(const ChessPiece& piece, const ChessPiece& targetPiece, const ChessBoard& board) const;

    /**
     * @brief Destructor for ChessPiece class.
     */
    ~ChessPiece() = default;
};

/**
 * @class Pawn
 * @brief Represents a pawn chess piece.
 */
class Pawn : public ChessPiece {
public:
    /**
     * @brief Constructor for Pawn class.
     * @param color The color of the pawn.
     * @param position The initial position of the pawn.
     */
    Pawn(ChessPieceColor color, std::string position)
            : ChessPiece(color, std::move(position), PieceType::Pawn) {}
};

/**
 * @class Bishop
 * @brief Represents a bishop chess piece.
 */
class Bishop : public ChessPiece{
public:
    /**
     * @brief Constructor for Bishop class.
     * @param color The color of the bishop.
     * @param position The initial position of the bishop.
     */
    Bishop(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::Bishop) {}
};

/**
 * @class Knight
 * @brief Represents a knight chess piece.
 */
class Knight : public ChessPiece{
public:
    /**
     * @brief Constructor for Knight class.
     * @param color The color of the knight.
     * @param position The initial position of the knight.
     */
    Knight(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::Knight) {}
};

/**
 * @class Rook
 * @brief Represents a rook chess piece.
 */
class Rook : public ChessPiece{
public:
    /** 
     * @brief Constructor for Rook class.
     * @param color The color of the rook.
     * @param position The initial position of the rook.
     */
    Rook(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::Rook) {}
};

/**
 * @class Queen
 * @brief Represents a queen chess piece.
 */
class Queen : public ChessPiece{
public:
    /**
     * @brief Constructor for Queen class.
     * @param color The color of the queen.
     * @param position The initial position of the queen.
     */
    Queen(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::Queen) {}
};

/**
 * @class King
 * @brief Represents a king chess piece.
 */
class King : public ChessPiece{
public:
    /**
     * @brief Constructor for King class.
     * @param color The color of the king.
     * @param position The initial position of the king.
     */
    King(ChessPieceColor color, std::string position)
    : ChessPiece(color, std::move(position), PieceType::King) {}
};

/**
 * @class EmptyPiece
 * @brief Represents an empty square on the chess board.
 */
class EmptyPiece : public ChessPiece {
public:
    /**
     * @brief Constructor for EmptyPiece class.
     * @param position The position of the empty square.
     */
    EmptyPiece(const std::string& position)
    : ChessPiece(ChessPieceColor::None, position, PieceType::None) {}
};




