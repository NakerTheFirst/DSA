#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long hash(long keyToHash, long tabSize);

// Todo:
// Resolve collision issue using open addressing with linear probing
// Create input checking function to run print on demand, in between add()

struct dataTest{
    long key;
    char value[8];
    long index;
};

int main() {

    // New and delete operators usage
    // int x;
    // int* ptr = new int[x];
    // delete[] ptr;

    string command;
    int sizeValue;
    bool stopper = false;
    long n;

    // Take number of test cases
    cin >> n;

    dataTest* data;

    while (!stopper) {

        cin >> command >> sizeValue;
        if (command == "size") {
            dataTest* data = new dataTest[sizeValue];
        }

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

        stopper = true;
    }

    return 0;
}

long hash(long keyToHash, long tabSize) {



    return keyToHash % tabSize;
}
