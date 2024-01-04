#include "Main.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);


    ChessBoard game(whitePlayer,blackPlayer);

    game.displayBoard();

    game.movePiece("A2", "A3");

    game.displayBoard();

    game.movePiece("B7", "B6");

    game.displayBoard();

    game.movePiece("A4", "B5");

    game.displayBoard();
    return 0;
}