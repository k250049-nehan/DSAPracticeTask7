#include <iostream>
#include <string>

using namespace std;

void playGameDirect(int targetNumber, int playerTurn) {
    int guess;
    cout << "Player " << playerTurn << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == targetNumber) {
        cout << "Congratulations! Player " << playerTurn << " guessed the correct number (" << targetNumber << ") and wins!\n";
        return;
    } else if (guess < targetNumber) {
        cout << "Too low!\n";
    } else {
        cout << "Too high!\n";
    }

    int nextPlayer = (playerTurn == 1) ? 2 : 1;
    playGameDirect(targetNumber, nextPlayer);
}

int main() {
    int targetNumber = 42;
    cout << "--- Number Guessing Game (Direct Recursion) ---\n";
    playGameDirect(targetNumber, 1);
    return 0;
}