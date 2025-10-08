#include <iostream>
using namespace std;

const int SIZE = 3;

/// <summary>
/// Initializes the Tic-Tac-Toe board by filling all positions with empty spaces.
/// </summary>
/// <param name="board">A 3x3 character array representing the game board.</param>
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

/// <summary>
/// Displays the current Tic-Tac-Toe board.
/// </summary>
/// <param name="board">A 3x3 character array representing the current game state.</param>
void displayBoard(const char board[SIZE][SIZE]) {
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---+---+---" << endl;
        }
    }
    cout << endl;
}

/// <summary>
/// Checks whether a move is valid.
/// </summary>
/// <param name="board">A 3x3 character array representing the current game board.</param>
/// <param name="row">The row index (0–2) where the player wants to move.</param>
/// <param name="col">The column index (0–2) where the player wants to move.</param>
/// <returns>True if the move is valid and false, otherwise.</returns>
bool isValidMove(const char board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    return true;
}

/// <summary>
/// Places the player's mark ('X' or 'O') at the specified position.
/// </summary>
/// <param name="board">A 3x3 character array representing the game board.</param>
/// <param name="row">The row index (0–2) where the player wants to place their mark.</param>
/// <param name="col">The column index (0–2) where the player wants to place their mark.</param>
/// <param name="player">The character ('X' or 'O') representing the current player.</param>
void makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    board[row][col] = player;
}

/// <summary>
/// Checks whether the specified player has won the game.
/// </summary>
/// <param name="board">A 3x3 character array representing the current game board.</param>
/// <param name="player">The character ('X' or 'O') representing the player to check.</param>
/// <returns>True if the player has three in a row (horizontally, vertically, or diagonally) and false, otherwise.</returns>
bool checkWin(const char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }
    return false;
}

/// <summary>
/// Checks whether the game has resulted in a draw.
/// </summary>
/// <param name="board">A constant 3x3 character array representing the current game board.</param>
/// <returns>True if all spaces are filled and no player has won and false, otherwise</returns>
bool isDraw(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// Runs the full Tic-Tac-Toe game between two players until a win or draw occurs.
/// Includes input validation to prevent crashes on invalid input.
/// </summary>
void playGame() {
    char board[SIZE][SIZE];
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameOver = false;
    cout << "Player 1: X, Player 2: O" << endl;

    while (!gameOver) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";

        if (!(cin >> row >> col)) {
            cout << "Invalid input! Please enter numbers only (0-2)." << endl;
            cin.clear();             
            cin.ignore(1000, '\n');  
            continue;
        }

        if (!isValidMove(board, row, col)) {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        makeMove(board, row, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        }
        else if (isDraw(board)) {
            displayBoard(board);
            cout << "Game drawn!" << endl;
            gameOver = true;
        }
        else {
            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    playGame();
}
