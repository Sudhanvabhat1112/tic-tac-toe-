#include <stdio.h>

// Function to display the current state of the board
void display_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check for a win
char check_win(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // If no winner
    return ' ';
}

// Function to check if the board is full
int board_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not full
            }
        }
    }
    return 1; // Full
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char player = 'X';
    char winner = ' ';

    printf("Welcome to Tic-Tac-Toe!\n");

    // Game loop
    while (winner == ' ' && !board_full(board)) {
        // Display current board
        display_board(board);

        // Get player move
        printf("Player %c's turn. Enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; // Adjust to 0-based indexing
        col--;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Make the move
            board[row][col] = player;

            // Check for a win
            winner = check_win(board);

            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    // Display the final board
    display_board(board);

    // Display the result
    if (winner != ' ') {
        printf("Player %c wins!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
