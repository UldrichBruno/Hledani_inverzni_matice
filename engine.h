#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct step {
    int typeOfStep;
    double coef;
    unsigned int line;
};

#define MAX_SIZE_OF_MATRIX 50

class Gauss {
    int DIM = 0;
    double matrix[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    int numberOfstep = 0;
    struct step steps[];
    double findCoef(int lineNullHead, int lineReadHead) {
        return (-1 * (matrix[lineNullHead][lineReadHead] / matrix[lineReadHead][lineReadHead]));
    }

    bool check(int line, int col) {
        return matrix[line][col] != 0;
    }

    bool checkSingular(int numOfSteps, int DIM){
        return numOfSteps<DIM;
    }

public:
    void HST();
    void read(int inputDIM, string path);
    void print();
    void moveLine(int line);
    void nullateElement(int lineNullHead, int lineReadHead);
    void transponate();
    void makeOnes();
};

void Gauss::nullateElement(int lineNullHead, int lineReadHead) {
    steps[numberOfstep].typeOfStep = 0;
    steps[numberOfstep].coef = findCoef(lineNullHead, lineReadHead);
    steps[numberOfstep].line = lineNullHead;
    for (int i = 0; i < DIM; i++) {
        matrix[lineNullHead][i] = matrix[lineNullHead][i] + matrix[lineReadHead][i] * steps[numberOfstep].coef;
    }
    numberOfstep++;


}

void Gauss::HST() {
    int numOfLoops = 0;
    Start:
    for (int i = 0; i < DIM; i++) {         //ReadHead
        if (check(i, i) == 1) {
            for (int x = i + 1; x < DIM; x++) {    //NullHead
                nullateElement(x, i);
            }
        } else {
            numOfLoops++;
           if (checkSingular(numOfLoops, DIM)==1) {
               moveLine(i);
               goto Start;
           } else{
               cout << "Given matrix is singular!" << endl;
               exit(2);
           }
        }
    }
        }
void Gauss::print() {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            cout << setw(7) << setprecision(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Gauss::read(int inputDIM, string path) {
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

void Gauss::moveLine(int lineReadHead) {
    steps[numberOfstep].typeOfStep = 1;
    steps[numberOfstep].coef = 0;
    steps[numberOfstep].line = lineReadHead;
    numberOfstep++;

    double opmatrix[MAX_SIZE_OF_MATRIX];

    for (int k = 0; k < DIM; k++) {
        opmatrix[k] = matrix[lineReadHead][k];
    }

    for (int i = lineReadHead; i < DIM; i++) {
        for (int k = 0; k < DIM; k++) {
            matrix[i][k] = matrix[i + 1][k];
        }
    }

    for (int k = 0; k < DIM; k++) {
        matrix[DIM][k] = opmatrix[k];
    }
}

void Gauss::transponate() {
    steps[numberOfstep].typeOfStep = 2;
    steps[numberOfstep].coef = 0;
    steps[numberOfstep].line = 0;
    numberOfstep++;

    double opElement;

    for (int i = 0; i < DIM; i++) {
        for (int j = i; j < DIM; j++) {
            opElement = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = opElement;
        }
    }
}

void Gauss::makeOnes() {
    steps[numberOfstep].typeOfStep = 3;
    steps[numberOfstep].coef = 0;
    steps[numberOfstep].line = 0;
    numberOfstep++;

    for (int i = 0; i < DIM; i++) {
        for (int j = i; j < DIM; j++) {
            matrix[i][j] = matrix[i][j] / matrix[i][i];
        }
    }
}
/*void Gauss::transform(){
    float Imatrix[MAX_SIZE_OF_MATRIX][MAX_SIZE_OF_MATRIX];
    for (int i=0;i<DIM;i++)
        for (int j=0;j<DIM;j++) {
            Imatrix[i][i] = 1;
            Imatrix[i][j] = 0;
        }
    for (int k = 0; k < numberOfstep; k++){
        print();
        switch(steps[k].typeOfStep) {
            case 0:     //nullateElement
                for (int j = 0; j < DIM; j++) {
                    matrix[steps[k].line][j] = matrix[steps[k].line][j] + matrix[steps[k].line][j] * steps[k].coef;
                }
                break;
            case 1:     //moveLine
                double opMatrix[MAX_SIZE_OF_MATRIX];
                for (int k = 0; k < DIM; k++){
                    opMatrix[k]=matrix[steps[k].line][k];
                }

                for (int i = steps[k].line; i<DIM; i++) {
                    for (int k = 0; k < DIM; k++){
                        matrix[i][k]=matrix[i+1][k];
                    }
                }
                for (int k = 0; k < DIM; k++){
                    matrix[DIM][k] = opMatrix[k];
                }
                break;
            case 2:     //transponate
                double opElement;
                for (int i = 0; i < DIM; i++) {
                    for (int j = i; j < DIM; j++) {
                        opElement = matrix[i][j];
                        matrix [i][j] = matrix [j][i];
                        matrix [j][i] = opElement;
                    }
                }
                break;
            case 3:     //makeOnes
                for (int i = 0; i < DIM; i++) {
                    for (int j = 0; j < DIM; j++) {
                        matrix [i][j]= matrix [i][j]/matrix[i][i];
                    }
                }
                break;
            default:
                exit(3);
        }
    }
}*/