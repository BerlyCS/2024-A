#include <array>
#include <iostream>
#include <vector>

using namespace std;

const size_t SIZE{ 8 };

void printBoard(const array<array<bool, SIZE>, SIZE>& board) {
    for (const auto& row : board) {
        for (const auto& element : row)
            cout << ' ' << (element ? 'Q' : '.');
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col, const vector<int>& prevRows) {
    for (int prevRow = 0; prevRow < prevRows.size(); ++prevRow) {
        int prevCol = prevRows[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col))
            return false;
    }
    return true;
}

void solveNQueens(int row, vector<int>& prevRows, array<array<bool, SIZE>, SIZE>& board) {
    if (row == SIZE) {
        printBoard(board); // Print current valid configuration
        return;
    }

    for (int col = 0; col < SIZE; ++col) {
        if (isSafe(row, col, prevRows)) {
            prevRows.push_back(col);
            board[row][col] = true;

            solveNQueens(row + 1, prevRows, board);

            prevRows.pop_back();
            board[row][col] = false;
        }
    }
}

int main() {
    array<array<bool, SIZE>, SIZE> board{};
    vector<int> prevRows;

    solveNQueens(0, prevRows, board);

    return 0;
}

