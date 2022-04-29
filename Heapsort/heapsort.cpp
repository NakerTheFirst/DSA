#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Todo: Create heap sorting function
// Todo: Create heapify function
// Todo: Create a valid output format for larger arrays

long sort(int A, int n);

int main() {

//    cout << sort(5, 4) << endl;

    bool end = false;
    int loopIter = 0;
    int n;
    int k;
    long *tab;
    tab = new long{};

    // Set the number of test cases
    cin >> n;

    while (!end) {

        // Set the size of an array
        cin >> k;
        tab[k];

        // Insert elements
        for (int i = 0; i < k; ++i) {
            cin >> tab[i];
        }
        cout << endl;

        // Print unsorted
        for (int i = 0; i < k; ++i) {
            cout << tab[i] << " ";
        }
        cout << endl;

        // Print sorted - needs a fix
//        for (int i = 0; i < k; ++i) {
//            cout << tab[i] << " ";
//        }
//        cout << endl;

        ++loopIter;

        // Exit the loop
        if (loopIter == n) end = true;
    }

    delete [] tab;
    return 0;
}

//long sort(int A, int n) {
//
//    int* A = new int[n];
//
//    for (int i = n - 1; i > 0; --i) {
//
//        // Take size of an A int table
//        cout << n;
//        int temp;
//
//        // Swap elements
//        temp = A[i];
//        A[i] = A[0];
//        A[0] = temp;
//
//
//    }
//    delete [] A;
//    return A;
//}