#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long hash(long keyToHash, long tabSize);

// Todo: Fix the add function
// Todo: Fix the print function
// Todo: Add collision issue solution using open addressing with linear probing
// Todo: Create the delete function

struct dataTest {
    long key;
    char value[8];
    long index;
};

int main() {

    string command;
    int sizeValue;
    int n;
    int iter = 0;
    int addIter = 0;
    bool stopper = false;

    // Take number of test cases
    cin >> n;

    dataTest* data;

    loop:
    while (!stopper) {

        commands:
        cin >> command;

        // Check command input and redirect
        if (command == "size") goto size;
        if (command == "add") goto add;
        if (command == "print") goto print;
        if (command == "delete") goto del;
        if (command == "stop") goto stop;

        // Safe lock for input errors
        return -1;

        size:
        if (command == "size") {
            cin >> sizeValue;
            data = new dataTest[sizeValue+3];
            goto commands;
        }

        add:
        // addIter = 0;
        if (command == "add") {
            for (int i = 0; i < sizeValue; ++i) {
                cin >> data[i].key >> data[i].value;
                data[i].index = hash(data[i].key, sizeValue);
                cout << data[i].index << " " << data[i].key << " " << data[i].value << "end?" << endl;
            }
            /*addIter += 1;*/
            goto commands;
        }

        print:
        if (command == "print") {
            for (int i = 0; i < iter; ++i) {
                cout << data[i].index << " " << data[i].key << " " << data[i].value << endl;
            }
            cout << data[iter].index << " " << data[iter].key << " " << data[iter].value << endl;
            goto commands;
        }

        del:
        if (command == "delete") {
            // delete
            goto commands;
        }

        stop:
        if (command == "stop") {
            stopper = true;
            iter += 1;
        }
    }

    stopper = false;
    if (iter != n) goto loop;

    delete[] data;

    return 0;
}

long hash(long keyToHash, long tabSize) {

    return keyToHash % tabSize;
}
