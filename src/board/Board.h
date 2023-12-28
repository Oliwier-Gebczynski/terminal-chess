#pragma once
#include "../player/Player.h"
#include "../chessPiece/ChessPiece.h"

#include "../../Main.h"

#define ANSI_RESET   "\033[0m"
#define ANSI_BLACK   "\033[30m"
#define ANSI_RED     "\033[31m"

class ChessBoard {
private:
    std::vector<ChessPiece> board_;

    Player whitePlayer_;
    Player blackPlayer_;

public:
    ChessBoard(Player whiteColor, Player blackColor)
            : whitePlayer_(whiteColor), blackPlayer_(blackColor) {
        initializeBoard();
    }

    void initializeBoard() {
        startPosition(ChessPieceColor::White);
        startPosition(ChessPieceColor::Black);
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
