#include "Main.h"

int main() {
    Board chessBoard(8, 8);

//    Pawn P1(ChessPieceColor::White, "A2");
//    Bishop B1(ChessPieceColor::Black, "B2");
//    Knight K1(ChessPieceColor::Black, "C2");
//    Rook R1(ChessPieceColor::Black, "D2");
//    Queen Q1(ChessPieceColor::Black, "E2");
//    King K11(ChessPieceColor::Black, "F2");
//
//    P1.display();
//    B1.display();
//    K1.display();
//    R1.display();
//    Q1.display();
//    K11.display();

    BlackPlayer B1;
    WhitePlayer W1;

    B1.addPiece(Rook(ChessPieceColor::Black, "A1"));
    W1.addPiece(Queen(ChessPieceColor::White, "C3"));
    B1.addPiece(Pawn(ChessPieceColor::Black, "A3"));

    std::cout << "Before remove ___________________________________" << std::endl;

    auto blackPieces = B1.getPieces();

    for (const auto& piece: blackPieces) {
        piece.display();
    }

    std::cout << "After remove ___________________________________" << std::endl;

    B1.removePiece("A1");
    auto blackPieces2 = B1.getPieces();

    for (const auto& piece: blackPieces2) {
        piece.display();
    }

    chessBoard.printChessboard();

    return 0;
}