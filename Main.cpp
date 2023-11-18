#include "Main.h"


int main() {
    Board chessBoard(8, 8);

    std::cout << "Color of B1: ";
    if (chessBoard.getSquareColor("B1") == SquareColor::White) {
        std::cout << "White\n";
    } else {
        std::cout << "Black\n";
    }

    std::cout << "Color of A1: ";
    if (chessBoard.getSquareColor("A1") == SquareColor::White) {
        std::cout << "White\n";
    } else {
        std::cout << "Black\n";
    }

    chessBoard.printChessboard();

    return 0;
}