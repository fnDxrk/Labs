#include <iostream>
#include <string>

using namespace std;

void f1() {
    short n;
    cin >> n;
    if(n == 0) return;
    f1();
    if(n > 0) cout << n << "\t";
}

void f2(int *a,int size,int currentIndex = 0) {
    if (currentIndex == size) return;

    bool negative = a[currentIndex] < 0;

    if (negative) cout << a[currentIndex] << "\t";
    f2(a,size,currentIndex+1);
    if (!negative) cout << a[currentIndex] << "\t";
}


void f3(int n) {
    if (n == 0) return;
    int nm = n % 2;
    n = n / 2;
    f3(n);
    cout << nm;
}

int main(){
    int arr[]{1,-5,2,10,-4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 25;

    //f1();
    //f2(arr,size);
    f3(n);
    cout << endl;
}