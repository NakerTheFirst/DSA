#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct dataTest {
    long key;
    long desired;
    char value[8];
};

long hash(long keyToHash, long tabSize);

int main() {

    dataTest temp{};
    string command;
    int sizeValue;
    int n;
    int h;
    int iter = 0;
    bool stopper = false;

    // Take number of test cases
    cin >> n;

    dataTest* data{};

    loop:
    while (!stopper) {

        cin >> command;

        if (command == "size") {
            cin >> sizeValue;
            data = new dataTest[sizeValue];
            for (int i = 0; i < sizeValue; ++i) {
                data[i].key = 0;
                data[i].desired = 0;
            }
            continue;
        }

        if (command == "add") {

            cin >> temp.key >> temp.value;
            h = hash(temp.key, sizeValue);
            temp.desired = h;

            int it = 1;

            while (data[h].key != 0) {
                h = hash(temp.key+it, sizeValue);
                ++it;
            }

            data[h].key = temp.key;
            strcpy(data[h].value, temp.value);

            data[h].desired = temp.desired;

            continue;
        }

        if (command == "print") {
            for (int i = 0; i < sizeValue; ++i) {
                if (data[i].key != 0) {
                    cout << i << " " << data[i].key << " " << data[i].value << endl;
                }
            }
            cout << endl;
            continue;
        }

        if (command == "delete") {

            cin >> temp.key;

            for (int i = 0; i < sizeValue; ++i) {
                if (data[i].key == temp.key) {

                    // Delete added data
                    data[i].desired = 0;
                    data[i].key = 0;
                    memset(data[i].value, 0, 8);

                    for (int j = 0; j < sizeValue; ++j) {

                        if (data[j].desired != j && data[j].desired != 0) {

                            int tmp = data[j].desired;

                            if (data[tmp].key == 0) {

                                // Swap index numbers with the data to delete
                                data[tmp].key = data[j].key;
                                data[tmp].desired = data[j].desired;
                                strcpy(data[tmp].value, data[j].value);

                                // Delete added data
                                data[j].desired = 0;
                                data[j].key = 0;
                                memset(data[j].value, 0, 8);
                                j = 0;
                            }
                        }
                    }
                }
            }
            continue;
        }

        if (command == "stop") {
            stopper = true;
            iter += 1;
        }
    }

    // Outer looper
    stopper = false;
    if (iter != n) goto loop;

    delete[] data;

    return 0;
}

long hash(long keyToHash, long tabSize) {
    return keyToHash % tabSize;
}