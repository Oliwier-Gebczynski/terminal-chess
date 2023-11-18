#pragma once
#include "../../Main.h"

enum class SquareColor {
    White,
    Black
};

class Board {
private:
    int rows;
    int cols;
    std::vector<std::vector<SquareColor>> boardColors;
    void initializeBoard();

public:
    Board(int rows, int cols) : rows(rows), cols(cols) {
        initializeBoard();
    }

    void printChessboard();

    SquareColor getSquareColor(const std::string& position);
};


