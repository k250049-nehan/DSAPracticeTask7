#include <iostream>
#include <string>

using namespace std;

const int N = 16;
int board[N];
int bestPlacement[N];
int maxFlags = 0;

int absoluteValue(int val) {
    return (val < 0) ? -val : val;
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || absoluteValue(board[i] - col) == absoluteValue(i - row)) {
            return false;
        }
    }
    return true;
}

void solveFlags(int row, int currentFlags) {
    if (row == N) {
        if (currentFlags > maxFlags) {
            maxFlags = currentFlags;
            for (int i = 0; i < N; i++) {
                bestPlacement[i] = board[i];
            }
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveFlags(row + 1, currentFlags + 1);
            board[row] = -1;
        }
    }

    solveFlags(row + 1, currentFlags);
}

int main() {
    for (int i = 0; i < N; i++) {
        board[i] = -1;
        bestPlacement[i] = -1;
    }

    solveFlags(0, 0);

    cout << "Maximum number of flags that can be placed on a 16x16 grid: " << maxFlags << endl;
    cout << "Flag placement (Row -> Column index):\n";
    for (int i = 0; i < N; i++) {
        cout << "Row " << i << " -> Column " << bestPlacement[i] << "\n";
    }

    return 0;
}