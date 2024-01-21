#pragma once
#include "../player/Player.h"
#include "../chessPiece/ChessPiece.h"

#include "../../Main.h"

/**
 * @class ChessBoard
 * @brief Represents a chess board with pieces and game-related functionalities.
 */
class ChessBoard {
private:
    std::vector<ChessPiece> board_;
    bool isInitialized_;

    Player whitePlayer_;
    Player blackPlayer_;
    Player currentPlayer_;

public:
    /**
     * @brief Constructor for the ChessBoard class.
     * @param whiteColor The player object representing the player with white pieces.
     * @param blackColor The player object representing the player with black pieces.
     */
    ChessBoard(Player whiteColor, Player blackColor)
            : whitePlayer_(whiteColor), blackPlayer_(blackColor), currentPlayer_(whiteColor) {
        initializeBoard();
    }

    /**
     * @brief Initializes the chess board with pieces in the starting positions.
     */
    void initializeBoard();

    /**
     * @brief Sets up the starting position of the chess board for a specific color.
     * @param color The color for which to set up the starting position.
     */
    void startPosition(ChessPieceColor color);

    /**
     * @brief Gets the vector representing the chess board.
     * @return Reference to the vector of ChessPiece objects.
     */
    std::vector<ChessPiece>& getBoard();

    /**
     * @brief Displays the current state of the chess board.
     */
    void displayBoard() const;

    /**
     * @brief Gets the ChessPiece at a specific position (mutable version).
     * @param position The position on the chess board.
     * @return Optional reference to the ChessPiece at the specified position.
     */
    std::optional<std::reference_wrapper<ChessPiece>> getChessPieceAt(const std::string& position);

    /**
     * @brief Gets the ChessPiece at a specific position (const version).
     * @param position The position on the chess board.
     * @return Optional copy of the ChessPiece at the specified position.
     */
    const std::optional<ChessPiece> getChessPieceAt(const std::string& position) const;

    /**
     * @brief Checks if a move from one position to another on the chess board is valid.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isMoveValid(const std::string& from, const std::string& to);

    /**
     * @brief Moves a chess piece from one position to another on the chess board.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     */
    void movePiece(const std::string& from, const std::string& to);

    /**
     * @brief Moves a specific chess piece to a target position on the chess board.
     * @param piece The chess piece to move.
     * @param targetPiece The target chess piece at the destination position.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     */
    void moveThis(ChessPiece& piece, ChessPiece& targetPiece, const std::string& from, const std::string& to);

    /**
     * @brief Checks if the player of the specified color is in checkmate.
     * @param color The color of the player (ChessPieceColor::White or ChessPieceColor::Black).
     * @return True if the player is in checkmate, false otherwise.
     */
    bool isCheckmate(ChessPieceColor color) const;

    /**
     * @brief Checks if a diagonal move from one position to another on the chess board is valid.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     * @return True if the diagonal move is valid, false otherwise.
     */
    bool isDiagonalMoveValid(const std::string &from, const std::string &to) const;

    /**
     * @brief Checks if a straight move from one position to another on the chess board is valid.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     * @return True if the straight move is valid, false otherwise.
     */
    bool isStraightMoveValid(const std::string &from, const std::string &to) const;

    /**
     * @brief Checks if the player of the specified color is in check.
     * @param color The color of the player (ChessPieceColor::White or ChessPieceColor::Black).
     * @return True if the player is in check, false otherwise.
     */
    bool isInCheck(ChessPieceColor color) const;

    /**
     * @brief Checks if a knight move from one position to another on the chess board is valid.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     * @return True if the knight move is valid, false otherwise.
     */
    bool isKnightMoveValid(const std::string &from, const std::string &to) const;

    /**
     * @brief Checks if a square on the chess board is blocked.
     * @param from The starting position of the move.
     * @param to The destination position of the move.
     * @return True if the square is blocked, false otherwise.
     */
    bool isSquareBlocked(const std::string &from, const std::string &to) const;

    /**
     * @brief Performs a chess move based on user input.
     */
    void makeMove();

    /**
     * @brief Switches the current player making a move.
     */
    void switchPlayer();

    /**
     * @brief Finds the king of the specified color on the chess board.
     * @param color The color of the king to find (ChessPieceColor::White or ChessPieceColor::Black).
     * @return Optional reference to the ChessPiece representing the king.
     */
    std::optional<std::reference_wrapper<const ChessPiece>> findKing(ChessPieceColor color) const;

    /**
     * @brief Clears the terminal screen.
     */
    void clearTerminal();
};
