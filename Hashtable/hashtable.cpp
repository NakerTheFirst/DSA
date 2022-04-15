#include <iostream>
using namespace std;

struct data {
    long key;
    char text[8];
};

long hash(data dataHash);
void insert(data dataIn);

int main() {

    // Take number of occurrences
    long n;
    cin >> n;
    data newStruct[n];

    // Take data to hash
    for (int i = 0; i < n; ++i) {
        cin >> newStruct[i].text;
    }


    /*  Print outputs
    for (int i = 0; i < n; ++i) {
        cout << newStruct[i].text  << endl;
    }
    */


    string choice;

    //if (choice == 'size') return -1;
    //if (choice == 'add') return -1;
    //if (choice == 'delete') return -1;
    //if (choice == 'print') return -1;

    /*
    for(int i = 0; i < 5; ++i) {
        newStruct[i].text[i] = 'Name';
    }
    */

    /*
    for (int i = 0; i < 5; ++i) {
        cout << newStruct[i].key << " " << newStruct[i].text << endl;
    }
     */
    return 0;
}


long hash(data testStruct) {
    long hashCode = testStruct.key % 11;
    return hashCode;
}

void insert(data dataIn) {

}