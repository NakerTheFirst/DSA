#include <iostream>
using std::cin, std::cout, std::endl, std::string;

// B530 lub B102 można doktora złapać
// 3 zadania zaliczają

// with a pinch of a salt

// n do zdefiniowania (rozmiar tablicy)

//int tab[n];

int sort(int A, int n);


int main() {

    cout << sort(5, 4)

    return 0;
}

long sort(int A, int n) {

    for (int i = n - 1; i > 0; --i) {
        // Take size of an A int table
        int* A = new int[n];
        cout << n;
        int temp;
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;

    }
    delete [] A;
    return A;
}