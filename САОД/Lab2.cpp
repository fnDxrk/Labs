#include <iostream>

int M = 0;
int C = 0;

using namespace std;

void clearData(){
    M = 0;
    C = 0;
}

void FillInc(int *a, int size){
    for(int i=0; i < size; i++)
        a[i] = i+1;
}

void FillDec(int*a, int size){
    for(int i=0; i < size; i++)
        a[i] = size-i;
} 

void FillRand(int *a, int size){
    for(int i=0; i < size; i++) {
        a[i] = (rand()%1000) + 1;
    }
}


void PrintMas(int*a, int size){
    for(int i=0; i<size; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
} 

int CheckSum(int*a, int size) {
    int sum = 0;
    for(int i=0; i<size; i++)
        sum += a[i];
    return sum;
} 

int RunNumber(int*a, int size) {
    int count = 1;
    for (int i=1; i<size; i++) {
        count = (a[i] < a[i-1]) ? count+1: count;
    }
    return count;
} 

void swap(int * a, int first, int second){
    M += 3;
    int temp = a[first];
    a[first] = a[second];
    a[second] = temp;
}

bool increase(int a, int b) {
    return a > b;
}

bool decrease(int a, int b) {
    return a < b;
}

void SelectSort(int * a, int size, bool(*pred)(int,int)){
    for (int i = 0; i < size - 1; i++) {
        int curSwap = a[i];                     //Значение курсора
        int curSwapInd = i;                     //Курсор
        for (int j = i + 1; j < size; j++) {
            C++;
            if (pred(curSwap, a[j])) {
                curSwapInd = j;
                curSwap = a[j];
            }
        }
        swap(a, i, curSwapInd);
        
    }
}

void EffectiveSelectSort(int * a, int size, bool(*pred)(int,int)){
    for (int i = 0; i < size - 1; i++) {
        int curSwap = a[i];                     //Значение курсора
        int curSwapInd = i;                     //Курсор
        for (int j = i + 1; j < size; j++) {
            C++;
            if (pred(curSwap, a[j])) {
                curSwapInd = j;
                curSwap = a[j];
            }
        }
        if (curSwapInd != i)
            swap(a, i, curSwapInd);
        
    }
}

void checkSort(int *a, int size) {
    
    int n = size;

    cout << "Изначальный массив:\t";
    PrintMas(a, n);
    cout << "Контрольная сумма \t";
    cout << CheckSum(a, n) << endl;
    cout << "Подсчет серий \t";
    cout <<  RunNumber(a, n) << endl;

    EffectiveSelectSort(a, n, increase);
    cout << "\nОтсортированный массив:\t";
    PrintMas(a, n);
    cout << "Контрольная сумма \t";
    cout << CheckSum(a, n) << endl;
    cout << "Подсчет серий \t";
    cout <<  RunNumber(a, n) << endl;
    

    int Mt = 3 * (n - 1);
    cout << "Количество пересылок в теории \t";
    cout << Mt << endl;
    cout << "Количество пересылок \t";
    cout << M << endl;
    
    int Ct = (n * n - n) / 2;
    cout << "Количество сравнений в теории \t";
    cout << Ct << endl;
    cout << "Количество сравнений \t";
    cout << C << endl;

    clearData();
}

int main(){
    int n = 10;
    int a[n];
    
    FillInc(a, n);
    cout << "---------------------Проверяем для возрастающего массива---------------------" << endl;
    checkSort(a, n);

    cout << "\n\n\n";

    FillDec(a, n);
    cout << "---------------------Проверяем для убывающего массива---------------------" << endl;
    checkSort(a, n);
    cout << "\n\n\n";

    FillRand(a, n);
    cout << "---------------------Проверяем для случайного массива---------------------" << endl;
    checkSort(a, n);

    return 0;
}