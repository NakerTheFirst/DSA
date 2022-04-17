#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long hash(long keyToHash, long tabSize);

// Either:
// Resolve collision issue using open addressing
// Create input checking function to run print on demand, in between add()

int main() {

    struct dataTest{
        long key;
        char value[8];
        long index;
    };

    long n;

    // Take number of test cases
    cin >> n;

    // Add function
    // N is the number of test cases, the capacity of array is determined by size function - CHANGE
    dataTest data[n];
    for (int i = 0; i < n; ++i) {
        cin >> data[i].key >> data[i].value;
        data[i].index = data[i].key;
    }

    // Print function
    for (int i = 0; i < n; ++i) {
        cout << data[i].key << " " << data[i].value << endl;
    }

    // Hashing
    for (int i = 0; i < n; ++i) {
        data[i].index = hash(data[i].key, n);
    }

    // Debugging
    for (int i = 0; i < n; ++i) {
        cout << data[i].index << " " << data[i].key << " " << data[i].value << "\n";
    }

    return 0;
}

long hash(long keyToHash, long tabSize) {



    return keyToHash % tabSize;
}
