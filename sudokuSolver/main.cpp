#include <iostream>
using namespace std;

// Size of the Sudoku grid
const int SIZE = 9;

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a specific position
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if the number already exists in the same row or column
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in the same 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    // The number can be placed at the current position
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    // Find an empty position in the grid
    bool isEmpty = false;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If there are no empty positions, the puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 at the current position
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the remaining puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If the current number doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No number can be placed at the current position, puzzle unsolvable
    return false;
}

int main() {
    int grid[SIZE][SIZE];

    // Read the Sudoku puzzle from the user
    cout << "Enter the Sudoku puzzle (0 for empty cells):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    // Solve the Sudoku puzzle
    if (solveSudoku(grid)) {
        cout << "Sudoku solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
