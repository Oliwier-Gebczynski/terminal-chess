#include "Main.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);


    ChessBoard game(whitePlayer,blackPlayer);

    game.displayBoard();

    game.movePiece("B2", "B4");

    game.displayBoard();

    game.movePiece("C1", "A3");

    game.displayBoard();

    game.movePiece("B4", "B5");

    game.displayBoard();

    game.movePiece("A3", "E7");

    game.displayBoard();

    game.movePiece("E7", "F8");

    game.displayBoard();

    int somexd;

    somexd = 0;

    return 0;
}