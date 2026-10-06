#include <iostream>
#include <string>

using namespace std;

const int ROWS = 6;
const int COLS = 6;

char grid[ROWS][COLS] = {
    {'D', 'S', 'S', 'F', 'D', 'F'},
    {'S', 'S', 'S', 'F', 'S', 'D'},
    {'D', 'S', 'S', 'S', 'S', 'F'},
    {'F', 'S', 'F', 'S', 'S', 'F'},
    {'S', 'S', 'S', 'D', 'S', 'F'},
    {'S', 'F', 'S', 'S', 'S', 'H'}
};

bool visited[ROWS][COLS] = {false};

int currentPathX[36];
int currentPathY[36];
int bestPathX[36];
int bestPathY[36];

int currentPathLength = 0;
int bestPathLength = 0;
int minWindCount = 1000000;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void findPath(int x, int y, int currentWind) {
    currentPathX[currentPathLength] = x;
    currentPathY[currentPathLength] = y;
    currentPathLength++;

    if (x == 5 && y == 5) {
        if (currentWind < minWindCount) {
            minWindCount = currentWind;
            bestPathLength = currentPathLength;
            for (int i = 0; i < currentPathLength; i++) {
                bestPathX[i] = currentPathX[i];
                bestPathY[i] = currentPathY[i];
            }
        }
        currentPathLength--;
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && !visited[nx][ny] && grid[nx][ny] != 'F') {
            int windAddition = (grid[nx][ny] == 'D') ? 1 : 0;
            findPath(nx, ny, currentWind + windAddition);
        }
    }

    visited[x][y] = false;
    currentPathLength--;
}

int main() {
    int initialWind = (grid[0][0] == 'D') ? 1 : 0;
    findPath(0, 0, initialWind);

    cout << "--- Drone Delivery Path Summary ---\n";
    cout << "Minimum High-Wind (D) Cells Encountered: " << minWindCount << "\n";

    cout << "\nBlocked No-Fly Zones ('F'):\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'F') {
                cout << "(" << i << ", " << j << ") ";
            }
        }
    }

    cout << "\n\nSafest Path Followed (Coordinates):\n";
    for (int i = 0; i < bestPathLength; i++) {
        cout << "(" << bestPathX[i] << ", " << bestPathY[i] << ")";
        if (i < bestPathLength - 1) cout << " -> ";
    }
    cout << endl;

    return 0;
}