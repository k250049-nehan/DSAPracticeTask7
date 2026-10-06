#include <iostream>
#include <string>

using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim, int currentDim = 0, int index = 0) {
    if (currentDim >= dim) return 0;

    if (index >= sizes[currentDim]) {
        return recursiveArraySum(arr, sizes, dim, currentDim + 1, 0);
    }

    return arr[currentDim][index] + recursiveArraySum(arr, sizes, dim, currentDim, index + 1);
}

int main() {
    int dim = 3;
    int sizes[] = {3, 4, 2};

    int row0[] = {10, 20, 30};
    int row1[] = {5, 15, 25, 35};
    int row2[] = {100, 200};

    int* arr[] = {row0, row1, row2};

    int totalSum = recursiveArraySum(arr, sizes, dim);
    cout << "Total Sum of all elements in jagged array: " << totalSum << endl;

    return 0;
}