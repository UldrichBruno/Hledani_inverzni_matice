#include <iostream>
#include "engine.h"

int main() {
    int inputDIM;
    Gauss g;
    cout << "Input dim of matrix";
    cin >> inputDIM;

    string path;
    cout << "Input path";
    cin >> path;

    g.read(3,path);
    g.print();
    return 0;
}
