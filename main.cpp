#include <iostream>
#include "engine.h"

int main() {
    int inputDIM;
    Gauss g;
    cout << "Input dim of matrix";
    cin >> inputDIM;

    string path;        //C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    cout << "Input path";
    cin >> path;

    g.read(inputDIM,path);
    g.print();
    g.HST();
    g.print();
    g.transponate();
   // g.HST();
   // g.transponate();
    g.print();
    return 0;
}
