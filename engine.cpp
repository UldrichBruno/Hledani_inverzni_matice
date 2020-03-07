#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct step{
    float keof;
    unsigned int line;

};
#define MAX_SIZE_OF_MATRIX 50

class Gauss{
    int DIM;
    int RealSizeOfMatrix = 0;
    struct step steps[];
    float matrix[MAX_SIZE_OF_MATRIX ][MAX_SIZE_OF_MATRIX ];

public:
    Gauss();
    void HST();
    void read(int inputDIM, string path);
    void print();


};

void Gauss::HST(){
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void Gauss::print(){
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << setw(7) << setprecision(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void Gauss::read(int inputDIM, string path){
    DIM = inputDIM;
    int x;
    unsigned int SizeOfCol;
    ifstream inFile;
    inFile.open(path);
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> x) {

        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < DIM; j++) {
                matrix[i][j] = x;
                inFile >> x;
            }
        }

    }

    inFile.close();
}