#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

void FillInc(int *a, int size){
    for(int i=0; i < size; i++)
    a[i] = i+1;
}

void FillDec(int*a, int size){
    for(int i=0; i < size; i++)
        a[i] = size-i;
}

void FillRand(int *a, int size){
    for(int i=0; i < size; i++)
        a[i] = (rand()%100) + 1;
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

void PrintMas(int*a, int size){
    for(int i=0; i<size; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main(){
    int a[ARRAY_SIZE];
    cout << "По возрастанию \t";
    FillInc(a,ARRAY_SIZE);
    PrintMas(a,ARRAY_SIZE);
    cout << "Контрольная сумма \t";
    cout << CheckSum(a,ARRAY_SIZE) << endl;
    cout <<"Подсчет серий \t";
    cout << RunNumber(a,ARRAY_SIZE) << endl;

    cout << endl;

cout << "По убыванию \t";
FillDec(a,ARRAY_SIZE);
PrintMas(a,ARRAY_SIZE);
cout << "Контрольная сумма \t";
cout << CheckSum(a,ARRAY_SIZE) << endl;
cout << "Подсчет серий \t";
cout << RunNumber(a,ARRAY_SIZE) << endl;

cout << endl;

cout << "Рандомные числа \t";
FillRand(a,ARRAY_SIZE);
PrintMas(a,ARRAY_SIZE);

cout << "Контрольная сумма \t";
cout << CheckSum(a,ARRAY_SIZE) << endl;
cout << "Подсчет серий \t";
cout << RunNumber(a,ARRAY_SIZE) << endl;
}