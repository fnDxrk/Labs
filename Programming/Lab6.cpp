#include <iostream>

using namespace std;

void triangleProperty(int a, int b, int c, int *Perimeter, int* Square) {
    while (1) {
        if (a >= b + c || b >= a + c || c >= a + b) {
            cout << "Ошибка. Вы ввели не правильные стороны треугольника.\n\n";
            cout << "Введите сторону a : "; cin >> a;
            cout << "Введите сторону b : "; cin >> b;
            cout << "Введите сторону c : "; cin >> c;
        }
        break;
    }

    cout << endl;

    *Perimeter = a + b + c;
    *Square =  a * b * c;
}

int main() {
    int a, b, c;
    int Perimeter, Square;
    cout << "Введите сторону a : "; cin >> a;
    cout << "Введите сторону b : "; cin >> b;
    cout << "Введите сторону c : "; cin >> c;

    triangleProperty(a, b, c, &Perimeter, &Square);

    cout << "Периметр треугольника : " << Perimeter << endl;
    cout << "Площадь треугольника : " << Square << endl;

    return 0;
}