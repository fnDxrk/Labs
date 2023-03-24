#include <iostream>
#include <string>

using namespace std;

struct telephoneDirectory {
    string name;
    string surname;
    string adress;
    long int number;
};

void swap(string *a, string *b) {
  string temp = *a;
  *a = *b;
  *b = temp;
}

void swapNumber(long int *a, long int *b) {
  long int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(telephoneDirectory* arr, int* index) {
    int size = 4;
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].name < arr[min_idx].name) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx].name, &arr[i].name);
            swap(&arr[min_idx].surname, &arr[i].surname);
            swap(&arr[min_idx].adress, &arr[i].adress);
            swapNumber(&arr[min_idx].number, &arr[i].number);
        }
    }
}

void selectionSortNumber(telephoneDirectory* arr, int* index) {
    int size = 4;
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].number < arr[min_idx].number) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[min_idx].name, &arr[i].name);
            swap(&arr[min_idx].surname, &arr[i].surname);
            swap(&arr[min_idx].adress, &arr[i].adress);
            swapNumber(&arr[min_idx].number, &arr[i].number);
        }
    }
}


int main() {    

    telephoneDirectory arr[4] = { 
                                  {"Philipp", "Andruschenko", "Novaya", 89133075868},
                                  {"Igor", "Sirotkin", "Voshod", 89648109258}, 
                                  {"Artem", "Rusetskiy", "Nikitina", 88005553535},
                                  {"Ivan", "Petrov", "Pushkina", 86669995555}
                                };
    
    int arr1, arr2;

    selectionSort(arr, &arr1);

    for (int i = 0; i < 4; i++) {
        cout << arr[i].name << " " << arr[i].surname << " " << arr[i].adress << " " << arr[i].number << endl;
    }

    cout << endl;

    selectionSortNumber(arr, &arr2);

    for (int i = 0; i < 4; i++) {
        cout << arr[i].name << " " << arr[i].surname << " " << arr[i].adress << " " << arr[i].number << endl;
    }

    cout << endl;

    return 0;
}