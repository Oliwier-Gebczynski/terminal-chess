#include "../board/Board.h"

void ChessBoard::startPosition(ChessPieceColor color){
    for (char file = 'A'; file <= 'H'; file++) {
        std::string position;
        std::string backRank = (color == ChessPieceColor::Black) ? "8" : "1";

        if (color == ChessPieceColor::Black) {
            position = std::string(1, file) + "7";
        } else if (color == ChessPieceColor::White) {
            position = std::string(1, file) + "2";
        }

        board_.emplace_back(color, position, PieceType::Pawn);
    }

    std::string backRank = (color == ChessPieceColor::Black) ? "8" : "1";
    board_.emplace_back(color, "A" + backRank, PieceType::Rook);
    board_.emplace_back(color, "B" + backRank, PieceType::Knight);
    board_.emplace_back(color, "C" + backRank, PieceType::Bishop);
    board_.emplace_back(color, "D" + backRank, PieceType::Queen);
    board_.emplace_back(color, "E" + backRank, PieceType::King);
    board_.emplace_back(color, "F" + backRank, PieceType::Bishop);
    board_.emplace_back(color, "G" + backRank, PieceType::Knight);
    board_.emplace_back(color, "H" + backRank, PieceType::Rook);
}

void ChessBoard::displayBoard() const {
    const int boardSize = 8;

    std::cout << "  ";
    for (char col = 'A'; col <= 'H'; ++col) {
        std::cout << std::setw(4) << col;
    }
    std::cout << "\n";

    for (int row = boardSize; row >= 1; --row) {
        std::cout << row << " ";

        for (int col = 1; col <= boardSize; ++col) {
            const ChessPiece* piece = nullptr;
            for (const auto& p : board_) {
                if (p.getPosition() == std::string(1, 'A' + col - 1) + std::to_string(row)) {
                    piece = &p;
                    break;
                }
            }

            if ((row + col) % 2 == 0) {
                std::cout << "\033[48;2;200;200;200m";
            } else {
                std::cout << "\033[48;2;255;255;255m";
            }

            if (piece) {
                if (piece->getColor() == ChessPieceColor::Black) {
                    std::cout << "\033[38;2;0;0;0m";
                } else {
                    std::cout << "\033[38;2;255;0;0m";
                }
                std::cout << std::setw(4) << piece->typeToSymbol();
            } else {
                std::cout << std::setw(4) << " ";
            }

            std::cout << "\033[0m";
        }

        std::cout << "\n";
    }
}
