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
		x[i] = rand() % 10000 + 1;
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

int main() {
	int* arr, N, M, C;

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


	printf("\n\n\t|\tM+C\t|\t\tM факт + C факт\t\t\t     |");
	printf("\nn\t|\tТеор.\t|  Возрастающий   |   Случайный   |    Убывающий     |");
	printf("\n------------------------------------------------------------------------------");


	
	int M1, C1;

	FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t|\t%d\t  |\t%d", N, (3 * (N - 1) + (((N * N) - N) / 2)), M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("\t  |\t%d\t     |", M + C);

	N = 200;
	arr = new int[N];

	FillRand(arr, N);
	bubbleSort(arr, N, M, C);
	FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t|\t%d\t  |\t%d", N, (3 * (N - 1) + (((N * N) - N) / 2)), M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("\t  |\t%d\t     |", M + C);

	N = 300;
	arr = new int[N];

	FillRand(arr, N);
	bubbleSort(arr, N, M, C);
	FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t|\t%d\t  |\t%d", N, (3 * (N - 1) + (((N * N) - N) / 2)), M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("\t  |\t%d\t     |", M + C);

	N = 400;
	arr = new int[N];

	FillRand(arr, N);
	bubbleSort(arr, N, M, C);
	FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t|\t%d\t  |\t%d", N, (3 * (N - 1) + (((N * N) - N) / 2)), M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("\t  |\t%d\t     |", M + C);

	N = 500;
	arr = new int[N];

	FillRand(arr, N);
	bubbleSort(arr, N, M, C);
	FillInc(arr, N);
	bubbleSort(arr, N, M1, C1);
	printf("\n%d\t|\t%d\t|\t%d\t  |\t%d", N, (3 * (N - 1) + (((N * N) - N) / 2)), M1 + C1, M + C);
	FillDec(arr, N);
	bubbleSort(arr, N, M, C);
	printf("\t  |\t%d\t     |", M + C);
	
	printf("\n");
	return 0;
}