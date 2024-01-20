#include "Main.h"
#include "src/player/Player.h"
#include "src/board/Board.h"

int main() {
    Player whitePlayer(ChessPieceColor::White);
    Player blackPlayer(ChessPieceColor::Black);

    ChessBoard chessBoard(whitePlayer, blackPlayer);

    while (true) {
        chessBoard.makeMove();
    }

    return 0;
}