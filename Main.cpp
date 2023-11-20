#include "Main.h"

int main() {
    Board chessBoard(8, 8);

    Pawn P1(ChessPieceColor::White, "A2");
    Bishop B1(ChessPieceColor::Black, "B2");
    Knight K1(ChessPieceColor::Black, "C2");
    Rook R1(ChessPieceColor::Black, "D2");
    Queen Q1(ChessPieceColor::Black, "E2");
    King K11(ChessPieceColor::Black, "F2");

    P1.display();
    B1.display();
    K1.display();
    R1.display();
    Q1.display();
    K11.display();

    chessBoard.printChessboard();

    return 0;
}