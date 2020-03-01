#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
double x;



void print_matrix(double matrix[DIM][DIM]);
void Row_Reduce(double matrix[DIM][DIM]);

void print_matrix(double matrix[DIM][DIM]) // Outputs the matrix
{

    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            cout << setw(7) << setprecision(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

/*void Row_Reduce(double matrix[DIM][DIM]) {
     int nrows = DIM; // number of rows
     int ncols = DIM; // number of columns

    int lead = 0;

    while (lead < nrows) {
        double d, m;

        for (int r = 0; r < nrows; r++) { // for each row ...*/
            /* calculate divisor and multiplier */
           /* d = matrix[lead][lead];
            m = matrix[r][lead] / matrix[lead][lead];

            for (int c = 0; c < ncols; c++) { // for each column ...
                if (r == lead)
                    matrix[r][c] /= d;               // make pivot = 1
                else
                    matrix[r][c] -= matrix[lead][c] * m;  // make other = 0
            }
        }

        lead++;
    //    print_matrix(matrix);
    }*/


/*int col_elim(int i){
    for (int k=0;k<i;k++){
        for (int l=0;l<i;l++){

        }
    }
}
*/



int main() {
    int DIM;
    double matrix[DIM][DIM];
    cout << "Input dimension of square matrix" << endl;
    cin >> DIM;
    ifstream inFile;

    inFile.open("C:\\Users\\Uzivatel\\CLionProjects3\\Hledani_inverzni_matice\\matrix.txt");
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
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    inFile.close();

    void print_matrix(double matrix[DIM][DIM]);
    //void Row_Reduce(double matrix[DIM][DIM]);
   // void print_matrix(double matrix[DIM][DIM]);

return 0;
}
