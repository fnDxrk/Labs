#include <iostream>
#include <string>
#include <functional>

#define TT template<typename T>

using namespace std;

struct telephoneDirectory {
    string name;
    string surname;
    string adress;
    long int number;
};

void swapt(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void printArray(telephoneDirectory* arr, int* index) {
    for (int i = 0; i < 4; i++) {
        cout << arr[index[i]].name << " "
             << arr[index[i]].surname << " "
             << arr[index[i]].adress << " "
             << arr[index[i]].number << endl;
    }
}

void selectionSortName(telephoneDirectory *array, int* index) {
    int size = 4;
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[index[i]].name < array[index[min_idx]].name)
            min_idx = i;
        }
        swapt(index[min_idx], index[step]);
    }
}

void selectionSortNumber(telephoneDirectory *array, int* index) {
    int size = 4;
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[index[i]].number < array[index[min_idx]].number)
            min_idx = i;
        }
        swapt(index[min_idx], index[step]);
    }
}


TT void selectionSortUn(telephoneDirectory *array, int* index, function<T(telephoneDirectory)> getField) {
    int size = 4;
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (getField(array[index[i]]) < getField(array[index[min_idx]]))
            min_idx = i;
        }
        swapt(index[min_idx], index[step]);
    }
}

int main() {    

    telephoneDirectory arr[4] = { 
                                  {"Philipp", "Andruschenko", "Novaya", 89133075868},
                                  {"Igor", "Sirotkin", "Voshod", 89648109258}, 
                                  {"Artem", "Rusetskiy", "Nikitina", 88005553535},
                                  {"Ivan", "Petrov", "Pushkina", 86669995555}
                                };
    
    int arr1[4] = {0, 1, 2, 3}, 
        arr2[4] = {0, 1, 2, 3};

    //selectionSortName(arr, arr1);

    selectionSortUn<string>(arr, arr1, [](telephoneDirectory d){
        return d.name;
    });

    cout << endl;

    printArray(arr, arr1);

    selectionSortUn<long int>(arr, arr2, [](telephoneDirectory d){
        return d.number;
    });
    // selectionSortNumber(arr, arr2);

    cout << endl;

    printArray(arr, arr2);

    cout << endl << endl;

    return 0;
}