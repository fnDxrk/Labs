#include <iostream>
#include <cmath>

using namespace std;

/* 1
int date_easter(int year) {
    int a = year % 19;
    int b = year % 4;
    int c = year % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;
    return f;
}

int main() {
    int year;
    cout << "Введите год : "; cin >> year;
    while (1) {
        if (year <= 325) {
            cout << "Год неверный. Введите год заново : "; cin >> year;
        }
        else {
            break;
        }
    }
    if (date_easter(year) <= 26) {
        cout << "Пасха будет праздноваться " << date_easter(year) + 4 << " апреля" << endl;
    }
    else {
        cout << "Пасха будет праздноваться " << date_easter(year) - 26 << " мая" << endl;
    }
    return 0;
}
*/

/* 2
float degree(float x, int n) {
    float temp = x;
    if (n > 0) {
        for (int i = 1; i < n; i++) {
            x *= temp;
        }
    } else if (n < 0) {
        n *= -1;
        for (int i = 1; i < n; i++) {
            x *= temp;
        }
        x = 1/x;
    } else x = 1;
    return x;
}

int main() {
    float x; int n;
    cout << "Введите число : "; cin >> x;
    cout << "Введите степень : "; cin >> n;
    cout << "Вывод : " << degree(x, n) << endl;
    return 0;
}
*/

const float PI = 3.1415926535;

float cosinus(float x) {
    x = fmod(x, 2 * PI);
    int n = 1;
    float temp = 1.0;
    float result = 0.0;
    do {
        result += temp;
        temp *= -1 * powf(x, 2) / ((2 * n - 1) * (2 * n));
        n++;
    }
    while (fabs(temp) > 0.0001);
    return result;
}


int main() {
    float x;
    cout << "Введите X : "; cin >> x;
    float y = cosinus(x);

    cout << "Мой косинус равен ";
    return 0;
}

