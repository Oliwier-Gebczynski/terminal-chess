#include "Main.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);


    ChessBoard game(whitePlayer,blackPlayer);

    game.displayBoard();
    return 0;
}