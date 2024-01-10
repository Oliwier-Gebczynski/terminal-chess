#pragma once
#include "../player/Player.h"
#include "../chessPiece/ChessPiece.h"

#include "../../Main.h"

class ChessBoard {
private:
    std::vector<ChessPiece> board_;
    bool isInitialized_;

    Player whitePlayer_;
    Player blackPlayer_;

public:
    ChessBoard(Player whiteColor, Player blackColor)
            : whitePlayer_(whiteColor), blackPlayer_(blackColor) {
        initializeBoard();
    }

    void initializeBoard();
    void startPosition(ChessPieceColor color);
    std::vector<ChessPiece>& getBoard();
    void displayBoard() const;

    std::optional<std::reference_wrapper<ChessPiece>> getChessPieceAt(const std::string& position);
    const std::optional<ChessPiece> getChessPieceAt(const std::string& position) const;

    bool isMoveValid(const std::string& from, const std::string& to);
    void movePiece(const std::string& from, const std::string& to);

    bool isPieceInPath(const std::string& from, const std::string& to) const;

    void moveThis(ChessPiece& piece, ChessPiece& targetPiece, const std::string& from, const std::string& to);
    bool isCheckmate(ChessPieceColor color) const;

    bool isDiagonalMoveValid(const std::string &from, const std::string &to) const;

    bool isStraightMoveValid(const std::string &from, const std::string &to) const;
};
