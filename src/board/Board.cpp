#include "../../Main.h"

void Board::initializeBoard(){
    boardColors.resize(rows, std::vector<SquareColor>(cols, SquareColor::Black));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i + j) % 2 == 1) {
                boardColors[i][j] = SquareColor::White;
            }
        }
    }
}

SquareColor Board::getSquareColor(const std::string& position){
    int row = position[1] - '1';
    int col = position[0] - 'A';

    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return boardColors[row][col];
    }
}

void Board::printChessboard() {
    for (const auto& row : boardColors) {
        for (const auto& color : row) {
            if (color == SquareColor::White) {
                std::cout << "   ";
            } else {
                std::cout << " ■ ";
            }
        }
        std::cout << std::endl;
    }
}
