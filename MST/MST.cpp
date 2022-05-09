#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class vertices {
public:
    unsigned short vNumber;
    unsigned short idx;
};

class edges {
public:
    char eName[8];
    unsigned short eNumber;
    unsigned short eDesc[3];
};

int main() {

    vertices v{};
    edges e{};

    // Take number of vertices in a graph
    cin >> v.vNumber;

    // auto* sth = new unsigned short[v.vNumber];

    // Take vertices' index and description
    for (int i = 0; i < v.vNumber; ++i) {
        cin >> v.idx;
        cin >> e.eName;
    }

    cout <<

    // delete[] sth;

    return 0;
}
