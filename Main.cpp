#include "Main.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);


    ChessBoard game(whitePlayer,blackPlayer);

    game.displayBoard();

    game.movePiece("D2","D4");
    game.displayBoard();

    game.movePiece("C7","C5");
    game.displayBoard();

    game.movePiece("D8","A5");
    game.displayBoard();

    auto test = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test;

    game.movePiece("A5","A2");
    game.displayBoard();

    auto test2 = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test2;

    game.movePiece("A2","B2");
    game.displayBoard();

    auto test3 = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test3;


    game.movePiece("B2","C2");
    game.displayBoard();

    auto test4 = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test4;


    game.movePiece("C2","D3");
    game.displayBoard();

    auto test5 = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test5;

    game.movePiece("D3","D2");
    game.displayBoard();

    auto test6 = game.isInCheck(ChessPieceColor::White);
    std::cout << "test " << test6;

    return 0;
}