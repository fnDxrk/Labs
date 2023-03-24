#include <iostream>

using namespace std;

void stringLength(int** arr, int line) {
    for (int i = 0; i < line; i++) {
        for (int j = 1; j < arr[i][0]; j++) {
            arr[i][arr[i][0]] += arr[i][j];
        }
    }
}

int main() {

    uint line = 5;

    int **arr = new int*[line];

    for (int i = 0; i < line; i++) {
        int column = (2 + rand() % 8) + 1;
        arr[i] = new int[column];
        arr[i][0] = column - 1;
    }

    for (int i = 0; i < line; i++) {
        for (int j = 1; j < arr[i][0]; j++) {
            arr[i][j] = rand() % 100;
            arr[i][arr[i][0] + 1] = 0;
        }
    }

    stringLength(arr, line);

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < arr[i][0] + 1; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}