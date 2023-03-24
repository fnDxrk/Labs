#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void FillInc (int *x, int n) { 
	for (int i = 0; i < n; i++) {
		x[i] = i + 1;
	}
}

void FillDec (int *x, int n) { 
	for (int i = 0; i < n; i++) {
		x[i] = n - i;
	}
}  

void FillRand (int *x, int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 100 + 1;
	}
}

void PrintMas (int *x, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", x[i]);
	}
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

void shakerSort(int *mass, int count, int &M, int &C){
    C = 0, M = 0;
    int left = 0, right = count - 1;
    int flag = 1; 
    while ((left < right) && flag > 0) {
    flag = 0;
    for (int i = left; i < right; i++){
        C++;
        if (mass[i] > mass[i + 1]) {  
            double t = mass[i];
            mass[i] = mass[i + 1];
            mass[i + 1] = t;
            flag = 1;
            M = M + 3;
        }
    }
    right--; 
    for (int i = right; i>left; i--){
        C++;
        if (mass[i - 1]>mass[i]){ 
            double t = mass[i];
            mass[i] = mass[i - 1];
            mass[i - 1] = t;
            flag = 1;   
            M = M + 3;
        }
    }
    left++; 
  }
}

void bubbleSort(int * array, int size, int &flag1, int &flag2) {
	flag1 = 0, flag2 = 0;
	for (int step = 0; step < size - 1; ++step) {
		for (int i = 0; i < size - step - 1; ++i) {
    		flag1++;
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag2 = flag2 + 3;
			}
		}
	}
}

int main(){
    setlocale(LC_ALL, "rus");
    int* arr, N, M2, C2, M, C;
    N = 100;

    

    arr = new int[N];
    FillRand(arr, N);
	PrintMas(arr, N);
	printf("\nКонтрольная сумма : %d", CheckSum(arr, N));
	printf("\nКол-во серий : %d", RunNumber(arr, N));
	printf("\n\n");
	bubbleSort(arr, N, M, C);
	PrintMas(arr, N);
	printf("\nКонтрольная сумма : %d", CheckSum(arr, N));
	printf("\nКол-во серий : %d", RunNumber(arr, N));

    arr = new int[N];

    printf("\n\n\t|\t\tMф + Cф пузырьковая\t\t     |\t\t      Мф + Сф шейкерная \t\t |\tМ + С теоретич.\t\t|");
	printf("\nn\t|  Возрастающий   |   Случайный   |    Убывающий     |  Возрастающий   |   Случайный   |    Убывающий    |\t\t\t\t|");
	printf("\n-------------------------------------------------------------------------------------------------------------------------------------------");

    int M1, C1;


    FillRand(arr, N);
    bubbleSort(arr, N, M, C);
    FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t  |\t%d\t", N, M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("  |\t%d\t     |", M + C);
    FillInc(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("\t    %d\t       |", M2 + C2);
    FillRand(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d     |", M2 + C2);
    FillDec(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d       | \t    %d         \t|", M2 + C2,  ((3 * (N * N - N)) / 4) + ((N * N - N) / 2));

    N = 200;
	arr = new int[N];

    FillRand(arr, N);
    bubbleSort(arr, N, M, C);
    FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t  |\t%d\t", N, M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("  |\t%d\t     |", M + C);
    FillInc(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("\t    %d\t       |", M2 + C2);
    FillRand(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d     |", M2 + C2);
    FillDec(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d       | \t   %d        \t|", M2 + C2,  ((3 * (N * N - N)) / 4) + ((N * N - N) / 2));

    N = 300;
	arr = new int[N];

    FillRand(arr, N);
    bubbleSort(arr, N, M, C);
    FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t  |\t%d\t", N, M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("  |\t%d\t     |", M + C);
    FillInc(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("\t    %d\t       |", M2 + C2);
    FillRand(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d    |", M2 + C2);
    FillDec(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d       | \t   %d       \t|", M2 + C2,  ((3 * (N * N - N)) / 4) + ((N * N - N) / 2));

    N = 400;
	arr = new int[N];

    FillRand(arr, N);
    bubbleSort(arr, N, M, C);
    FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t  |\t%d\t", N, M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("  |\t%d\t     |", M + C);
    FillInc(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("\t    %d\t       |", M2 + C2);
    FillRand(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d    |", M2 + C2);
    FillDec(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d      | \t   %d       \t|", M2 + C2,  ((3 * (N * N - N)) / 4) + ((N * N - N) / 2));

    N = 500;
	arr = new int[N];

    FillRand(arr, N);
    bubbleSort(arr, N, M, C);
    FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t  |\t%d\t", N, M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("  |\t%d\t     |", M + C);
    FillInc(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("\t    %d\t       |", M2 + C2);
    FillRand(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d    |", M2 + C2);
    FillDec(arr, N);
    shakerSort(arr, N, M2, C2);
    printf("     %d      | \t   %d       \t|", M2 + C2, ((3 * (N * N - N)) / 4) + ((N * N - N) / 2));

    printf("\n");
}