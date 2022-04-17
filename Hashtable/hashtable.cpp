#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Hash {
public:
    long key;
    char text[8];
    char sizeCheck[4];
    long tabSize; // tabSize can be directly accessed through an object
    long hash(long keyToHash) {
        return keyToHash % tabSize;
    }
};

int main() {

    struct dataTest{
        long key;
        char value[8];
        long index;
    };

    unsigned int n;

    // Take number of test cases
    cin >> n;

    dataTest data[n];
    for(int i = 0; i < n; ++i) {
        cin >> data[i].key >> data[i].value;
        data[i].index = data[i].key;
    }

    // Print function
    for(int i = 0; i < n; ++i) {
        cout << data[i].key << " " << data[i].value << endl;
    }

    // Hashing



//    Hash data[] = {0, "size", "size", 4, };
//    cin >> data.tabSize;
//
//    cout << data.sizeCheck << endl;
//    cin >> data.sizeCheck >> data.tabSize;
//    cout << data.sizeCheck << data.tabSize << endl;
//
//    for(int i = 0; i < data.tabSize; ++i) {
//        cin >> fCheck >> tabSize;
//
//        // "Size" function
//        if(fCheck == "size") {
//
//        }
//            // Set the text value of objects
//            for (int i = 0; i < n+5; ++i) {
//                cin >> newStruct[i].text;
//            }
//    }
    return 0;
}
//
//long hash(data testStruct) {
//    testStruct.key = testStruct.key % 739; // change 739 to tab size
//    return testStruct.key;
//}

