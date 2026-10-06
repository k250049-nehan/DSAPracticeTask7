#include <iostream>
#include <string>

using namespace std;

const int N = 5;

char grid[N][N] = {
    {'S', 'A', 'A', 'T', 'A'},
    {'T', 'A', 'A', 'A', 'G'},
    {'A', 'T', 'T', 'A', 'F'},
    {'A', 'A', 'A', 'T', 'G'},
    {'A', 'T', 'G', 'T', 'G'}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int sqPathX[25], sqPathY[25], sqLen = 0;
int foxPathX[25], foxPathY[25], foxLen = 0;

bool exploreSquirrel(int x, int y, int& acornsCollected, bool visited[N][N]) {
    visited[x][y] = true;
    sqPathX[sqLen] = x;
    sqPathY[sqLen] = y;
    sqLen++;

    if (grid[x][y] == 'A') acornsCollected++;
    if (acornsCollected == 7) return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] != 'T') {
            if (exploreSquirrel(nx, ny, acornsCollected, visited)) return true;
        }
    }

    if (grid[x][y] == 'A') acornsCollected--;
    sqLen--;
    visited[x][y] = false;
    return false;
}

bool exploreFox(int x, int y, int& gemsCollected, bool visited[N][N]) {
    visited[x][y] = true;
    foxPathX[foxLen] = x;
    foxPathY[foxLen] = y;
    foxLen++;

    if (grid[x][y] == 'G') gemsCollected++;
    if (gemsCollected == 6) return true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] != 'T') {
            if (exploreFox(nx, ny, gemsCollected, visited)) return true;
        }
    }

    if (grid[x][y] == 'G') gemsCollected--;
    foxLen--;
    visited[x][y] = false;
    return false;
}

void printGridPath(int pathX[], int pathY[], int len, char symbol) {
    char outGrid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) outGrid[i][j] = '.';
    }
    for (int i = 0; i < len; i++) {
        outGrid[pathX[i]][pathY[i]] = symbol;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << outGrid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    bool visitedSq[N][N] = {false};
    int acorns = 0;
    exploreSquirrel(0, 0, acorns, visitedSq);

    cout << "--- Squirrel Path Grid ('S') ---\n";
    printGridPath(sqPathX, sqPathY, sqLen, 'S');

    bool visitedFox[N][N] = {false};
    int gems = 0;
    exploreFox(2, 4, gems, visitedFox);

    cout << "\n--- Fox Path Grid ('F') ---\n";
    printGridPath(foxPathX, foxPathY, foxLen, 'F');

    return 0;
}