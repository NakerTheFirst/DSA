#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void heapify(int* tab, int n, int root);
void buildHeap(int* tab, int tabSize);
void sort(int* tab, int tabSize);

int main() {

    bool end = false;
    int loopIter = 0;
    int n, k;

    int *tab;
    tab = new int{};

    // Set the number of test cases
    cin >> n;

    while (!end) {

        // Set the size of an array
        cin >> k;
        tab[k] = {};
        
        // Insert elements
        for (int i = 0; i < k; ++i) {
            cin >> tab[i];
        }
        cout << endl;

        // Print unsorted
        for (int i = 0; i < k; ++i) {
            cout << tab[i] << " ";
        }
        cout << endl << endl;

        sort(tab, k);

        // Print sorted
        for (int i = 0; i < k; ++i) {
            cout << tab[i] << " ";
        }
        cout << endl << endl;

        ++loopIter;

        // Exit the loop
        if (loopIter == n) end = true;
    }

    delete [] tab;
    return 0;
}

void heapify(int* tab, int n, int root) {

    int largest = root;
    int l = 2*root + 1;
    int r = 2*root + 2;
    int temp;

    // If left child is larger than root
    if (l < n && tab[l] > tab[largest]) largest = l;

    // If right child is larger than largest
    if (r < n && tab[r] > tab[largest]) largest = r;

    // If largest is not a root
    if (largest != root) {
        temp = tab[root];
        tab[root] = tab[largest];
        tab[largest] = temp;
        heapify(tab, n, largest);
    }
}


void buildHeap(int* tab, int tabSize){

    for (int i = tabSize/2 - 1; i >= 0; --i) {
        heapify(tab, tabSize, i);
    }

}

void sort(int* tab, int tabSize) {

    long temp;
    buildHeap(tab, tabSize);

    for (int i = tabSize-1; i >= 0; --i) {

        for (int j = 0; j <= i; ++j) {
            cout << tab[j] << " ";
        }
        cout << endl;

        temp = tab[0];
        tab[0] = tab[i];
        tab[i] = temp;
        heapify(tab, i, 0);
    }
}
