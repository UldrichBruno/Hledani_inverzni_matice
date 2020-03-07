#include <iostream>
#include "engine.h"

int main() {
    int inputDIM;
    Gauss g;
    cout << "Input dim of matrix";
    cin>>inputDIM;
    g.read(3,"D:/Users/Dokumenty/GitHub/Hledani_inverzni_matice/matrix.txt");
    g.print();
    return 0;
}
