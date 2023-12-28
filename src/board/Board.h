#include "../../Main.h"

class ChessBoard {
private:
    std::vector<ChessPiece> board_;

    WhitePlayer whitePlayer_;
    BlackPlayer blackPlayer_;
    Player* currentPlayer_;

public:
    ChessBoard() : whitePlayer_(), blackPlayer_(), currentPlayer_(&whitePlayer_) {
        initializeBoard();
    }

    void initializeBoard() {
        board_.resize(64, ChessPiece::Empty);
        startPosition(ChessPieceColor::White);
        startPosition(ChessPieceColor::Black);
    }

    void displayBoard() const {
        const int boardSize = 8;

        // Nagłówki kolumn (litery od A do H)
        std::cout << "  ";
        for (char col = 'A'; col <= 'H'; ++col) {
            std::cout << std::setw(4) << col;
        }
        std::cout << "\n";

        for (int row = boardSize; row >= 1; --row) {
            // Numeracja wierszy
            std::cout << row << " ";

            for (int col = 1; col <= boardSize; ++col) {
                const ChessPiece& piece = board_[(row - 1) * boardSize + (col - 1)];

                // Kolorowanie tła dla lepszej czytelności
                if ((row + col) % 2 == 0) {
                    std::cout << "\033[48;2;200;200;200m";  // Szary kolor tła
                } else {
                    std::cout << "\033[48;2;255;255;255m";  // Biały kolor tła
                }

                // Wyświetlanie figury na danym polu
                if (piece.getType() == PieceType::None) {
                    std::cout << std::setw(4) << " ";  // Puste pole
                } else {
                    std::cout << std::setw(4) << piece.typeToString();
                }

                std::cout << "\033[0m";  // Resetowanie kolorów tła
            }

            std::cout << "\n";
        }
    }

    bool isMoveValid(const std::string& from, const std::string& to) const {
    }

    bool makeMove(const std::string& from, const std::string& to) {
        if (isMoveValid(from, to)) {
            return true;
        } else {
            return false;
        }
    }

    bool isCheckmate(ChessPieceColor color) const {

    }

    void startPosition(ChessPieceColor color);
};
