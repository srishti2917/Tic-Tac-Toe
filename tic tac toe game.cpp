#include <bits/stdc++.h>
class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void displayBoard() {
        std::cout << "\n";
        for (const auto& row : board) {
            for (const auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    bool isWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool isDraw() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    bool isValidMove(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-';
    }

public:
    TicTacToe() : board(3, std::vector<char>(3, '-')), currentPlayer('X') {}

    void playGame() {
        std::cout << "Welcome to Tic-Tac-Toe!\n";

        while (true) {
            displayBoard();
            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row and column: 0 1 2): ";
            std::cin >> row >> col;

            if (!isValidMove(row, col)) {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (isWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }

        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') {
            board = std::vector<std::vector<char>>(3, std::vector<char>(3, '-'));
            currentPlayer = 'X';
            playGame();
        } else {
            std::cout << "Thanks for playing!\n";
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
