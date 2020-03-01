#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int DIM;
    cout << "Input dimension of square matrix"<<endl;
    cin >> DIM;
    int matrix[DIM][DIM];
    int x;
    ifstream inFile;

    inFile.open("C:\\Users\\Uzivatel\\CLionProjects3\\Hledani_inverzni_matice\\matrix.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

        while (inFile >> x) {
            for (int i=0;i<DIM;i++){
                for (int j=0;j<DIM;j++){
                   matrix[i][j] = x;
                    inFile >> x;
                }
            }

        }
    for (int i=0;i<DIM;i++){
        for (int j=0;j<DIM;j++){
           cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }

    inFile.close();
        return 0;
}

