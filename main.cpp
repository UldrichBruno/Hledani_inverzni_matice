#include <iostream>
#include "engine.h"

int main() {
    int inputDIM;
    Gauss g;
    cout << "Input dim of matrix";
    cin >> inputDIM;

    string path;
    cout << "Input path";
    cin >> path;

    g.read(inputDIM,path);
    g.print();
    g.HST();
    g.print();
    return 0;
}
