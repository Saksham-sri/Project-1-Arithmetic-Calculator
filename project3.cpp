#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false; // If there's an empty space, it's not a draw yet
        }
    }
    return true; // All spaces are filled, it's a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X';
    int row, col;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true) {
        std::cout << "\nCurrent Board:\n";
        displayBoard(board);

        // Get player's move
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            std::cout << "\nPlayer " << currentPlayer << " wins!\n";
            displayBoard(board);
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            std::cout << "\nIt's a draw!\n";
            displayBoard(board);
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
