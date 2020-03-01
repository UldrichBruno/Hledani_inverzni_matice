#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int i=0;
    int j=0;
    int DIM;
    cout << "Input dimension of square matrix"<<endl;
    cin >> DIM;
    int matrix[i][j];
    int x;
    ifstream inFile;

    inFile.open("C:\\Users\\Uzivatel\\CLionProjects3\\Hledani_inverzni_matice\\matrix.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

        while (inFile >> x) {
            for (int j=0;j<DIM;j++){
            for (int i = 0; i < DIM; i++) {
                x >> matrix[i][j];
                inFile >> x;
                i = +i;
            }
            j=+j;
            }
        }
/*    for (int j=0;j<DIM;j++) {
        for (int i = 0; i, DIM; i++) {
            cout << matrix[i][j] << " ";
        }
    }
*/
    inFile.close();
        return 0;
}

