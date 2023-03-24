#include <iostream>

using namespace std;

/*
int main() {
    // Массивы
    int *A;
    int **B;
    // Кол-во элементов
    int m = 10;
    int k;

    cout << "Введите число, меньше " << m << " : "; 
    cin >> k;
    while (k >= m) {
        cout << "Ошибка. Введите число,меньше 10 :";
        cin >> k;
    }

    A = new int[m];
    B = new int *[k];

    for (int i = 0; i < k; i++) {
        B[i] = new int[m / k];
    }

    for (int i = 0; i < m; i++) {
        A[i] = rand() % 100;
        cout << A[i] << "\t";
    }
    cout << endl << endl;

    int temp = 0;
    if (m % k == 0) {
        for (int i = 0; i < (int)(m / k); i++) {
            for (int j = 0; j < k; j++) {
                    B[i][j] = A[j + (temp * k)];
                    cout << B[i][j] << "\t";
            }
        temp++;
        cout << endl;
        }
    }
    if (m % k != 0) {
        for (int i = 0; i < (int)(m / k) + 1; i++) {
            for (int j = 0; j < k; j++) {
                if (j + (temp * k) >= m) {
                    B[i][j] = 0; 
                }
                else B[i][j] = A[j + (temp * k)];
                cout << B[i][j] << "\t"; 
            }
        temp++;
        cout << endl;
        }
    }

    delete A;
    for (int i = 0; i < (m / k); i++)
        delete B[i];
    delete B;

    cout << endl;
    return 0;
}
*/

/*
int main() {
    int b, flag = 1, count = 0;

    cout << "Enter Arr size: "; cin >> b;

    int** A = new int*[b];

    for (int i = 0; i < b; i++) {
        A[i] = new int[i+1];
        for (int j = 0; j < (i + 1); j++) {
            A[i][j] = (j + 1) * (i + 1);
            count++;
            cout << A[i][j] << "\t";
        }
        printf("\n");
    }
    for (int i = 0; i < b; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
*/