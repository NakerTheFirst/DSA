#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long hash(long keyToHash, long tabSize);

// Todo: Resolve collision issue using open addressing with linear probing
// Todo: Fix print function
// Todo: Create a delete function

struct dataTest {
    long key;
    char value[8];
    long index;
};

int main() {

    string command;
    int sizeValue;
    long n;
    int iter = 0;
    bool stopper = false;

    // Take number of test cases
    cin >> n;

    dataTest* data;

    loop:
    while (stopper == false) {

        cin >> command;

        if (command == "size") {
            cin >> sizeValue;
            data = new dataTest[sizeValue+3];
        }

        commands:
        cin >> command;

        // Check command input and redirect to following etiquette
        if (command == "add") goto add;
        if (command == "print") goto print;
        if (command == "delete") goto del;
        if (command == "stop") goto stop;

        cout << command << endl;

        // Safe lock for input errors
        return -1;

        add:
        cout << command << endl;
        if (command == "add") {
            cin >> data[iter].key >> data[iter].value;
            data[iter].index = hash(data[iter].key, sizeValue);
        }

        goto commands;

        print:
        if (command == "print") {
            cout << data[iter].index << " " << data[iter].key << " " << data[iter].value << endl;
        }

        cin >> command;
        goto commands;

        del:
        if (command == "delete") {
            // delete
        }

        cin >> command;
        goto commands;

        stop:
        stopper = true;
        iter += 1;

    }

    stopper = false;
    if (iter != n) goto loop;

    delete[] data;

    return 0;
}

long hash(long keyToHash, long tabSize) {



    return keyToHash % tabSize;
}
