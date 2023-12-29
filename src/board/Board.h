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

    void initializeBoard() {
        if (!isInitialized_) {
            for (auto& piece : board_) {
                piece = EmptyPiece();
            }

            startPosition(ChessPieceColor::Black);
            startPosition(ChessPieceColor::White);
            isInitialized_ = true;
        }
    }

    void displayBoard() const;

    bool isMoveValid(const std::string& from, const std::string& to) const {
        return true;
    }

    bool makeMove(const std::string& from, const std::string& to) {
        if (isMoveValid(from, to)) {
            return true;
        } else {
            return false;
        }
    }

    bool isCheckmate(ChessPieceColor color) const {
        return true;
    }

    void startPosition(ChessPieceColor color);
};
