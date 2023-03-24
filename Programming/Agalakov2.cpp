#include <iostream>
#include <cmath>

using namespace std;

int pow(int a)
{
    return a * a;
}

int main() {

    int size = 2;

    int arrNumber[size];

    cout << "Введите координаты x и y : ";
    for (int i = 0; i < size; i++) {
        cin >> arrNumber[i];
    }
    cout << endl;

    int distance = sqrt(pow(arrNumber[0]) + pow(arrNumber[1]));

    if (distance % 2 != 0 && arrNumber[0] != 0 && arrNumber[1] != 0) {
        cout << "Белая зона" << endl;
    }   else cout << "Чёрная зона" << endl;

    return 0;
}