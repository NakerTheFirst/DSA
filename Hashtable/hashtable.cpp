#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

long hash(long keyToHash, long tabSize);

// Todo: Resolve collision issue using open addressing with linear probing
// Todo: Find a solution to etiquette usage in while/for loop

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
    int iter = 0;

    // Take number of test cases
    cin >> n;

    dataTest* data;

    loop:
    while (!stopper) {

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

        // Safe lock for input errors
        return -1;

        add:
        if (command == "add") {
            cin >> data[iter].key >> data[iter].value;
            data[iter].index = hash(data[iter].key, sizeValue);
        }

        cin >> command;
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

    if (iter != n) goto loop;

    delete[] data;

    return 0;
}

long hash(long keyToHash, long tabSize) {



    return keyToHash % tabSize;
}
