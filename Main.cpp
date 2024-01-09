#include "Main.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);


    ChessBoard game(whitePlayer,blackPlayer);

    game.displayBoard();

    game.movePiece("A2", "A4");

    game.displayBoard();

    game.movePiece("B7", "B5");

    game.displayBoard();

    game.movePiece("A4", "B5");

    game.displayBoard();

    game.movePiece("A1", "A7");

    game.displayBoard();

    game.movePiece("A7", "B8");

    game.displayBoard();
    return 0;
}