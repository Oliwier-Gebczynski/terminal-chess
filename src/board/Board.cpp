#include "../board/Board.h"

void ChessBoard::startPosition(ChessPieceColor color){
    for (char file = 'A'; file <= 'H'; file++) {
        std::string position;
        if (color == ChessPieceColor::Black) {
            position = std::string(1, file) + "7";
            board_.emplace_back(color, position, PieceType::Pawn);
        } else if (color == ChessPieceColor::White) {
            position = std::string(1, file) + "2";
            board_.emplace_back(color, position, PieceType::Pawn);
        }
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

    for (int row = boardSize; row >= 1; --row) {
        for (int col = 1; col <= boardSize; ++col) {
            const ChessPiece& piece = board_[(row - 1) * boardSize + (col - 1)];

            // Ustawienie koloru czcionki na podstawie koloru figury
            if (piece.getColor() == ChessPieceColor::Black) {
                std::cout << ANSI_BLACK;
            } else {
                std::cout << ANSI_RED;
            }

            // Wyświetlanie figury na danym polu
            if (piece.getType() == PieceType::None) {
                std::cout << " ";  // Puste pole
            } else {
                std::cout << piece.typeToString();
            }

            std::cout << ANSI_RESET;  // Resetowanie koloru czcionki
        }

        std::cout << "\n";
    }

}
