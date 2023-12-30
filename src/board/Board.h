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

    ChessPiece& getChessPieceAt(const std::string& position) {
        auto it = std::find_if(board_.begin(), board_.end(), [&position](const ChessPiece& piece) {
            return piece.getPosition() == position;
        });

        if (it != board_.end()) {
            return *it;
        } else {
            throw std::out_of_range("Position out of range");
        }
    }

    void movePiece(const std::string& from, const std::string& to) {
        ChessPiece& piece = getChessPieceAt(from);



        if (piece.isMoveValid(to)) {
            ChessPiece& targetPiece = getChessPieceAt(to);

            if (targetPiece.getType() == PieceType::Empty) {
                // Docelowe miejsce jest puste, przenieś figurę
                positionToPieceMap_[to] = piece;
                positionToPieceMap_[from] = EmptyPiece();

                std::cout << "Piece moved from " << from << " to " << to << std::endl;
                // Dodaj logikę specyficzną dla danej figury (jeśli potrzebna)
                // ...
            } else {
                std::cerr << "Invalid move: Target position is occupied" << std::endl;
            }
        } else {
            std::cerr << "Invalid move for piece from " << from << " to " << to << std::endl;
        }
    }

};
