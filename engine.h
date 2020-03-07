#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct step{
    int typeOfStep;
    float coef;
    unsigned int line;

};
#define MAX_SIZE_OF_MATRIX 50

class Gauss{
    int DIM = 0;
    float matrix[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int numberOfstep = 0;
    struct step steps[];
    float findCoeff (int lineNullHead, int lineReadHead ){

        return (-1 * (matrix[lineNullHead][lineReadHead] / matrix[lineReadHead][lineReadHead]));

    }
    bool check(int line, int col){
        return matrix[line][col]!=0;
    }
public:

    void HST();
    void read(int inputDIM, string path);
    void print();
    void moveLine(int line);
    void nullateElement(int lineNullHead, int lineReadHead);
};

void Gauss::nullateElement (int lineNullHead, int lineReadHead){
    steps[numberOfstep].typeOfStep = 0;
    steps[numberOfstep].coef = findCoeff(lineNullHead, lineReadHead);
    steps[numberOfstep].line = lineNullHead;
    for(int i=0;i<DIM;i++){
        matrix[lineNullHead][i] = matrix[lineNullHead][i] + matrix[lineReadHead][i] * steps[numberOfstep].coef;
    }
    numberOfstep++;

}

void Gauss::HST(){
    for (int i=0; i<DIM; i++) {         //ReadHead
        Start:
        if (check(i,i) ==1) {
            for (int x = i + 1; x < DIM; x++) {    //NullHead
                nullateElement(x,i);
            }
        }
      else{
        moveLine(i);
          goto Start;
      }
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

void Gauss::moveLine(int lineNullHead){
    steps[numberOfstep].typeOfStep = 1;
    steps[numberOfstep].coef = 0;
    steps[numberOfstep].line = lineNullHead;
    numberOfstep++;
    for (int j = 0; j < DIM; j++) {
        float opmatrix[lineNullHead][j];
        matrix[lineNullHead][j]=opmatrix[lineNullHead][j];
        matrix[DIM][j]=matrix[lineNullHead][j];
    }
    for (int k=0; k<DIM-lineNullHead;k++){
        float op2matrix[lineNullHead+k+1][k];
        matrix[lineNullHead-1][k]=op2matrix[lineNullHead][k];
    }


}