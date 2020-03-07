#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct step{
    int typeOfStep;
    float koef;
    unsigned int line;

};
#define MAX_SIZE_OF_MATRIX 50

class Gauss{
    int DIM;
    int RealSizeOfMatrix = 0;
    float matrix[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    struct step steps[];
    bool check(int line, int col){
        return matrix[line][col]!=0;
    }
public:

    void HST();
    void read(int inputDIM, string path);
    void print();
    void moveLine(int line);
};

void Gauss::HST(){
    for (int i=0; i<DIM; i++) {         //NullHead
        Start:
        if (check(i,i) ==1) {
            for (int x = i + 1; x < DIM; x++) {    //ReadHead
                nullateElement(x,i);
            }
        }
      else{
        moveLine(i);
        i=i+1;
          goto Start;
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

void Gauss::moveLine(int line){
    for (int j = 0; j < DIM; j++) {
        float opmatrix[line][j];
        matrix[line][j]=opmatrix[line][j];
        matrix[DIM][j]=matrix[line][j];
    }
    for (int k=0; k<DIM-line;k++){
        float op2matrix[line+k+1][k];
        matrix[line-1][k]=op2matrix[line][k];
    }


}