#include <iostream>
#include "engine.h"

int main() {
    int inputDIM;
    Gauss g;
    cout << "Input dimension of matrix";
    cin >> inputDIM;

    string path;        // C:/Users/Uzivatel/CLionProjects3/Hledani_inverzni_matice/matrix.txt
    cout << "Input path";
    cin >> path;

    g.read(inputDIM,path);
    cout <<"Given matrix"<<endl;
    g.print();
    g.HST();
    cout <<"Upper triangular matrix:"<<endl;
    g.print();
    g.transponate();
    g.HST();
    g.transponate();
    cout <<"Lower triangular matrix"<<endl;
    g.print();
    g.makeOnes();
    cout <<"Identity matrix:"<<endl;
    g.print();
    g.transform();
    g.print();
    return 0;
}
