#include <iostream>
#include <string>

using namespace std;

void player1Turn(int targetNumber);
void player2Turn(int targetNumber);

void player1Turn(int targetNumber) {
    int guess;
    cout << "Player 1, enter your guess (1-100): ";
    cin >> guess;

    if (guess == targetNumber) {
        cout << "Congratulations! Player 1 guessed the correct number (" << targetNumber << ") and wins!\n";
        return;
    } else if (guess < targetNumber) {
        cout << "Too low!\n";
    } else {
        cout << "Too high!\n";
    }

    player2Turn(targetNumber);
}

void player2Turn(int targetNumber) {
    int guess;
    cout << "Player 2, enter your guess (1-100): ";
    cin >> guess;

    if (guess == targetNumber) {
        cout << "Congratulations! Player 2 guessed the correct number (" << targetNumber << ") and wins!\n";
        return;
    } else if (guess < targetNumber) {
        cout << "Too low!\n";
    } else {
        cout << "Too high!\n";
    }

    player1Turn(targetNumber);
}

int main() {
    int targetNumber = 42;
    cout << "--- Number Guessing Game (Mutual Recursion) ---\n";
    player1Turn(targetNumber);
    return 0;
}