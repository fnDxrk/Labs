#include <iostream>
#include <string.h>

using namespace std;

//  struct school
//     {
//         int num_school;
//         int sum_grad;
//         int sum_come;
//     };

// int main () {
//     int n;
//     cout << "Введите количество школ: "; cin >> n;
//     school *a = new school[n];
//     school *b = new school[n];
//     float proc[n];
//     float index[n][2];
//     for (int i = 0; i < n; i++) {
//         cout << "Введите номер школы: "; cin >> a[i].num_school;
//         cout << "Введите количество выпускников: "; cin >> a[i].sum_grad;
//         cout << "Введите количество поступивших: "; cin >> a[i].sum_come;
//         index[i][1] = float(float(a[i].sum_come) / (float(a[i].sum_grad) / 100));
//         index[i][0] = float(i);
//     }

//     for (int i = n - 1; i >= 0; i--) {
//         for (int j = 0; j < i; j++) {
//             if (index[j][1] > index[j+1][1]) {
//               float tmp = index[j][0];
//               index[j][0] = index[j + 1][0];
//               index[j + 1][0] = tmp;
//             }
//         }   
//     }
    
//     for (int i = 0; i < n; i++) {
//         b[i].num_school = a[int(index[i][0])].num_school;
//         b[i].sum_grad = a[int(index[i][0])].sum_grad;
//         b[i].sum_come = a[int(index[i][0])].sum_come;
//     }

//     for (int i = 0; i < n; i++) {
//         cout << b[i].sum_grad << "\t" << index[i][1] << endl;
//     }

//     return 0;
// }



struct Room{
    int number;
    int square;
    string faculty;
    int numberResident;
};

int main() {
    int size;

    cout << "Введите кол-во комнат : "; cin >> size; cout << endl;
    
    Room *rooms = new Room[size];

    for (int i = 0; i < size; i++) {
        cout << "Введите номер комнаты : "; cin >> rooms[i].number;
        cout << "Введите площадь комнаты : "; cin >> rooms[i].square;
        cout << "Введите факультет комнаты : "; cin >> rooms[i].faculty;
        cout << "Введите кол-во проживающих в комнате : "; cin >> rooms[i].numberResident;
        cout << endl;
    }

    string* arrayFacultyTest = new string[size];

    int resultSize = 0;

    // for (int i = 0; i < size; i++) {
    //     int j = 0;
    //     for (; j < resultSize; j++) {
    //         if (rooms[i].faculty == arrayFacultyTest[j]) {
    //             break;
    //         }
    //     }
    //     if (rooms[i].faculty != arrayFacultyTest[j]) {
    //         arrayFacultyTest[resultSize] = rooms[i].faculty;
    //         resultSize++;
    //     }
    // }

    // string* arrayFaculty = new string[resultSize];

    // for (int i = 0; i < resultSize; i++) {
    //     arrayFaculty[i] = arrayFacultyTest[i];
    //     cout << arrayFaculty[i] << endl;
    // }


    for (int i = 0; i < size; i++) {
        bool isOriginal = true;
        for (int j = i; j >= 0; j--) {
            if (rooms[i].faculty == rooms[j].faculty && i != j) {
                isOriginal = false;
                break;
            }
        }
        if (isOriginal) {
            arrayFacultyTest[resultSize] = rooms[i].faculty;
            resultSize++;
        }
    }

    string* arrayFaculty = new string[resultSize];

    for (int i = 0; i < resultSize; i++) {
        arrayFaculty[i] = arrayFacultyTest[i];
        cout << arrayFaculty[i] << endl;
    }
    
    for (int i = 0; i < resultSize; i++) {
        int counterNumberResident = 0;
        int counterRoom = 0;
        int sumSquare = 0;
        float counterSquare = 0;
        for (int j = 0; j < size; j++) {
            if (arrayFaculty[i] == rooms[j].faculty) {
                counterRoom += 1;
                counterNumberResident += rooms[j].numberResident;
                sumSquare += rooms[j].square;
            }
        }
        counterSquare = (float)sumSquare / (float)counterNumberResident;
        
        cout << "Факультет " << arrayFaculty[i] << ":" << endl;
        cout << "Кол-во комнат : " << counterRoom << endl;
        cout << "Кол-во студентов : " << counterNumberResident << endl;
        cout << "Площадь на одного студента : " << counterSquare << endl;
        cout << endl;
    }

    return 0;
}