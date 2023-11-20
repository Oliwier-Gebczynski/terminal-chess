#include "Main.h"

int main() {
    Board chessBoard(8, 8);

    Pawn whitePawn(ChessPieceColor::White, "A2", PieceType::Pawn);

    whitePawn.display();

    chessBoard.printChessboard();

    return 0;
}