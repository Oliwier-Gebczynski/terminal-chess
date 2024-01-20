#include "../board/Board.h"

void ChessBoard::initializeBoard() {
    if (!isInitialized_) {
        startPosition(ChessPieceColor::Black);
        startPosition(ChessPieceColor::White);
        isInitialized_ = true;
    }
}

std::vector<ChessPiece>& ChessBoard::getBoard(){
    return board_;
}

void ChessBoard::startPosition(ChessPieceColor color){
    for (char file = 'A'; file <= 'H'; file++) {
        std::string position;
        std::string backRank = (color == ChessPieceColor::Black) ? "8" : "1";

        if (color == ChessPieceColor::Black) {
            position = std::string(1, file) + "7";
        } else if (color == ChessPieceColor::White) {
            position = std::string(1, file) + "2";
        }
        board_.emplace_back(color, position, PieceType::Pawn);
    }

    std::string backRank = (color == ChessPieceColor::Black) ? "8" : "1";
    board_.emplace_back(color, "A" + backRank, PieceType::Rook);
    board_.emplace_back(color, "B" + backRank, PieceType::Knight);
    board_.emplace_back(color, "C" + backRank, PieceType::Bishop);
    board_.emplace_back(color, "D" + backRank, PieceType::Queen);
    board_.emplace_back(color, "E" + backRank, PieceType::King);
    board_.emplace_back(color, "F" + backRank, PieceType::Bishop);
    board_.emplace_back(color, "G" + backRank, PieceType::Knight);
    board_.emplace_back(color, "H" + backRank, PieceType::Rook);
}

void ChessBoard::displayBoard() const {
    const int boardSize = 8;

    std::cout << "  ";
    for (char col = 'A'; col <= 'H'; ++col) {
        std::cout << std::setw(4) << col;
    }
    std::cout << "\n";

    for (int row = boardSize; row >= 1; --row) {
        std::cout << row << " ";

        for (int col = 1; col <= boardSize; ++col) {
            const ChessPiece* piece = nullptr;
            for (const auto& p : board_) {
                if (p.getPosition() == std::string(1, 'A' + col - 1) + std::to_string(row)) {
                    piece = &p;
                    break;
                }
            }

            if ((row + col) % 2 == 0) {
                std::cout << "\033[48;2;200;200;200m";
            } else {
                std::cout << "\033[48;2;255;255;255m";
            }

            if (piece) {
                if (piece->getColor() == ChessPieceColor::Black) {
                    std::cout << "\033[38;2;0;0;0m";
                } else {
                    std::cout << "\033[38;2;255;0;0m";
                }
                std::cout << std::setw(4) << piece->typeToSymbol();
            } else {
                std::cout << std::setw(4) << " ";
            }

            std::cout << "\033[0m";
        }

        std::cout << "\n";
    }
}

std::optional<std::reference_wrapper<ChessPiece>> ChessBoard::getChessPieceAt(const std::string& position) {
    for (auto& piece : board_) {
        if (piece.getPosition() == position) {
            return std::ref(piece);
        }
    }
    return std::nullopt;
}

const std::optional<ChessPiece> ChessBoard::getChessPieceAt(const std::string& position) const {
    for (const ChessPiece& piece : board_) {
        if (piece.getPosition() == position) {
            return piece;
        }
    }
    return std::nullopt;
}

bool ChessBoard::isMoveValid(const std::string& from, const std::string& to) {
    std::optional<std::reference_wrapper<ChessPiece>> pieceOpt = getChessPieceAt(from);
    std::optional<std::reference_wrapper<ChessPiece>> targetPieceOpt = getChessPieceAt(to);

    if (!pieceOpt.has_value()) {
        return false;
    }else if(!targetPieceOpt.has_value()){
        ChessPiece& piece = *pieceOpt;
        ChessPiece targetPiece = EmptyPiece(to);

        return piece.isMoveValid(piece, targetPiece, *this);
    }else{
        ChessPiece& piece = *pieceOpt;
        ChessPiece& targetPiece = *targetPieceOpt;

        return piece.isMoveValid(piece, targetPiece, *this);
    }
}

void ChessBoard::movePiece(const std::string& from, const std::string& to){
    std::optional<std::reference_wrapper<ChessPiece>> pieceOpt = getChessPieceAt(from);
    std::optional<std::reference_wrapper<ChessPiece>> targetPieceOpt = getChessPieceAt(to);

    auto tempTargetPiece = EmptyPiece(to);

    if (!targetPieceOpt.has_value()) {
        ChessPiece& piece = *pieceOpt;
        ChessPiece targetPiece = EmptyPiece(to);

        moveThis(piece, targetPiece, from, to);
    } else {
        ChessPiece& piece = *pieceOpt;
        ChessPiece& targetPiece = *targetPieceOpt;

        moveThis(piece, targetPiece, from, to);
    }
}

void ChessBoard::moveThis(ChessPiece& piece, ChessPiece& targetPiece, const std::string& from, const std::string& to) {
    if (piece.isMoveValid(piece, targetPiece, *this)) {
        if (targetPiece.getType() == PieceType::None || targetPiece.getColor() != piece.getColor()) {
            piece.setPosition(to);

            if (targetPiece.getType() != PieceType::None) {
                std::cout << "Piece captured at " << to << std::endl;
                board_.erase(std::remove_if(board_.begin(), board_.end(), [&targetPiece](const ChessPiece& p) {
                    return &p == &targetPiece;
                }), board_.end());
            }

            std::cout << "Piece moved from " << from << " to " << to << std::endl;
        } else {
            std::cerr << "Invalid move: Target position is occupied by own piece" << std::endl;
        }
    } else {
        std::cerr << "Invalid move for piece from " << from << " to " << to << std::endl;
    }
}

bool ChessBoard::isCheckmate(ChessPieceColor color) const {
    return true;
}

bool ChessBoard::isStraightMoveValid(const std::string& from, const std::string& to) const {
    char fromFile = from[0];
    char fromRank = from[1];
    char toFile = to[0];
    char toRank = to[1];

    int fileDiff = std::abs(toFile - fromFile);
    int rankDiff = std::abs(toRank - fromRank);

    int fileDir = (toFile > fromFile) ? 1 : (toFile < fromFile) ? -1 : 0;
    int rankDir = (toRank > fromRank) ? 1 : (toRank < fromRank) ? -1 : 0;

    char file = fromFile;
    char rank = fromRank;

    for (int i = 0; i < std::max(fileDiff, rankDiff); ++i) {
        // Move to the next square
        file += fileDir;
        rank += rankDir;

        // Check if the square is within the bounds of the chessboard
        if (file < 'A' || file > 'H' || rank < '1' || rank > '8') {
            return false;  // Out of bounds
        }

        // Check if there is a piece in the current square
        if (file != toFile && rank != toRank && getChessPieceAt(std::string(1, file) + std::string(1, rank))) {
            return false;  // Piece in the path
        }
    }

    return true;  // No piece in the path
}

bool ChessBoard::isDiagonalMoveValid(const std::string& from, const std::string& to) const {
    char fromFile = from[0];
    char fromRank = from[1];
    char toFile = to[0];
    char toRank = to[1];

    int fileDiff = std::abs(toFile - fromFile);
    int rankDiff = std::abs(toRank - fromRank);

    // Sprawdź, czy ruch jest po ukosie
    if (fileDiff != rankDiff) {
        return false;
    }

    int fileDir = (toFile > fromFile) ? 1 : (toFile < fromFile) ? -1 : 0;
    int rankDir = (toRank > fromRank) ? 1 : (toRank < fromRank) ? -1 : 0;

    char file = fromFile;
    char rank = fromRank;

    for (int i = 0; i < fileDiff; ++i) {
        // Przesuwaj się po ukosie
        file += fileDir;
        rank += rankDir;

        // Sprawdź, czy pole jest w granicach szachownicy
        if (file < 'A' || file > 'H' || rank < '1' || rank > '8') {
            return false;  // Out of bounds
        }

        // Check if there is a piece in the current square
        if (file != toFile && rank != toRank && getChessPieceAt(std::string(1, file) + std::string(1, rank))) {
            return false;  // Piece in the path
        }
    }

    return true;  // No piece in the path
}

bool ChessBoard::isInCheck(ChessPieceColor color) const {
    std::optional<std::reference_wrapper<const ChessPiece>> kingOpt = findKing(color);

    if (!kingOpt.has_value()) {
        return false;
    }

    const ChessPiece& king = *kingOpt;

    const std::string kingPosition = king.getPosition();

    // Check for diagonal threats (queens, bishops)
    for (const auto& piece : board_) {
        if (piece.getColor() != color) {
            if (isDiagonalMoveValid(piece.getPosition(), kingPosition)) {
                if (!isSquareBlocked(piece.getPosition(), kingPosition)) {
                    return true; // There is a diagonal threat
                }
            }
        }
    }

    // Check for straight threats (queens, rooks)
    for (const auto& piece : board_) {
        if (piece.getColor() != color) {
            if (isStraightMoveValid(piece.getPosition(), kingPosition)) {
                if (!isSquareBlocked(piece.getPosition(), kingPosition)) {
                    return true; // There is a straight threat
                }
            }
        }
    }

    // Check for knight threats
    for (const auto& piece : board_) {
        if (piece.getColor() != color && piece.getType() == PieceType::Knight) {
            if (isKnightMoveValid(piece.getPosition(), kingPosition)) {
                return true; // There is a knight threat
            }
        }
    }

    // No threats found
    return false;
}

bool ChessBoard::isSquareBlocked(const std::string& from, const std::string& to) const {
    int fromRank = from[1] - '1';
    int fromFile = from[0] - 'a';
    int toRank = to[1] - '1';
    int toFile = to[0] - 'a';

    int rankDelta = toRank - fromRank;
    int fileDelta = toFile - fromFile;

    int rankDirection = (rankDelta > 0) ? 1 : (rankDelta < 0) ? -1 : 0;
    int fileDirection = (fileDelta > 0) ? 1 : (fileDelta < 0) ? -1 : 0;

    int currentRank = fromRank + rankDirection;
    int currentFile = fromFile + fileDirection;

    while (currentRank != toRank || currentFile != toFile) {
        if (getChessPieceAt(std::string(1, static_cast<char>('a' + currentFile)) + std::to_string(1 + currentRank))) {
            return true; // Square is blocked
        }

        currentRank += rankDirection;
        currentFile += fileDirection;
    }

    return false; // Square is not blocked
}

bool ChessBoard::isKnightMoveValid(const std::string& from, const std::string& to) const {
    int fromRank = from[1] - '1';
    int fromFile = from[0] - 'a';
    int toRank = to[1] - '1';
    int toFile = to[0] - 'a';

    int rankDelta = std::abs(toRank - fromRank);
    int fileDelta = std::abs(toFile - fromFile);

    return (rankDelta == 2 && fileDelta == 1) || (rankDelta == 1 && fileDelta == 2);
}

std::optional<std::reference_wrapper<const ChessPiece>> ChessBoard::findKing(ChessPieceColor color) const {
    // Znajdź króla danego koloru na planszy
    for (const ChessPiece& piece : board_) {
        if (piece.getType() == PieceType::King && piece.getColor() == color) {
            return std::ref(piece);
        }
    }

    return std::nullopt;
}

void ChessBoard::switchPlayer() {
    if (currentPlayer_.getColor() == ChessPieceColor::White) {
        currentPlayer_ = blackPlayer_;
    } else {
        currentPlayer_ = whitePlayer_;
    }
}

void ChessBoard::clearTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif


}

void ChessBoard::makeMove() {
    std::cout << "Current player: ";
    if (currentPlayer_.getColor() == ChessPieceColor::White) {
        std::cout << "White";
    } else {
        std::cout << "Black";
    }
    std::cout << std::endl;

    // Check for check and display a message
    if (isInCheck(currentPlayer_.getColor())) {
        std::cout << "CHECK!" << std::endl;
    }

    displayBoard();

    std::string from, to;
    ChessPieceColor currentPlayerColor = currentPlayer_.getColor();

    // Prompt for a move until a valid move is entered
    do {
        std::cout << "Enter your move (E4, F5): ";
        std::cin >> from >> to;

        // Check if the piece at the 'from' position has the correct color
        auto pieceAtFrom = getChessPieceAt(from);
        if (!pieceAtFrom.has_value() || pieceAtFrom.value().get().getColor() != currentPlayerColor) {
            std::cout << "Invalid move. Try again." << std::endl;

            // Clear the input buffer to avoid infinite loop on invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    } while (true);

    if (isMoveValid(from, to)) {
        movePiece(from, to);

        // Clear the terminal using the custom function
        clearTerminal();

        // Check for check after the move and display a message
        if (isInCheck(currentPlayer_.getColor())) {
            std::cout << "CHECK!" << std::endl;
        }

        displayBoard();
        switchPlayer();
    } else {
        std::cout << "Invalid move." << std::endl;
    }
}