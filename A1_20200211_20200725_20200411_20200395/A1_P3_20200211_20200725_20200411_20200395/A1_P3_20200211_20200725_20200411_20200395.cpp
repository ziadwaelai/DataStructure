#include <iostream>

using namespace std;
template <typename t>
class Matrix{
private:
    int row_, col_;
    t **M;
public:
    Matrix() : row_(0), col_(0) {
    cout << "Enter # of rows: ";
        cin >> row_;
        if (row_ > 0){
            cout << "Enter # of cols: ";
            cin >> col_;
            if (col_ > 0){
                M = (t**) new t *[row_];
                for (int i = 0; i < row_; i++){
                    M[i] = (t*) new t[col_];
                }
            }
            cout << "Enter Elements for Rows And Columns: " << endl;
            for (int i = 0; i < row_; i++){
                for (int j = 0; j < col_; j++){
                    cin >> M[i][j];
                }
            }
        }
    }
    Matrix(int m, int n) : row_(m), col_(n) {
        M = (t**) new t *[row_];
        for (int i = 0; i < row_; i++){
            M[i] = (t*) new t[col_];
        }
    }

    ~Matrix(){
        if (col_ > 0){
            for (int i = 0; i < row_; i++)
                delete [] M[i];
        }
        if (row_ > 0)
            delete [] M;
    }
    Matrix<t> operator+(Matrix& M1){
            if (M1.M[row_] == M[col_]){
                for (int i = 0; i < row_; i++){
                    for (int j = 0; j < col_; j++){
                        cout << M1.M[i][j] + M[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        return M1;
    }
    Matrix<t> operator-(Matrix& M1){
        if (M1.M[col_] == M[row_]){
            if (M1.M[row_] == M[col_]){
                for (int i = 0; i < row_; i++){
                    for (int j = 0; j < col_; j++){
                        cout << M1.M[i][j] - M[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else
            cout << "Subtraction not possible!!";
        return M1;
    }
    Matrix<t> operator*(Matrix& M1){
        Matrix<t> M2(row_, col_);
        for (int i = 0; i < row_; i++){
               for (int j = 0; j < M1.col_; j++){
                    M2.M[i][j] = 0;
               }
        }
        for (int i = 0; i < row_; i++){
            for (int j = 0; j < M1.col_; j++){
                    for (int k = 0; k < col_; k++){
                        //cout << (M1.M[i][j]) * M[j][i] << "   ";
                        M2.M[i][j] += M[i][k] * M1.M[k][j];
                    }
                }
            cout << endl;
        }
        return M2;
    }
    Matrix<t>& transpose(Matrix<t>& M2){
        Matrix<t> M3(M2.col_, M2.row_);
        for (int i = 0; i < M2.row_; i++){
            for (int j = 0; j < M2.col_; j++){
                M3.M[i][j] = M2.M[j][i];
            }
        }
        for (int i = 0; i < M2.row_; i++){
            for (int j = 0; j < M2.col_; j++){
                M2.M[i][j] = M3.M[i][j];
            }
        }
        return M2;
    }
    friend ostream& operator<< (ostream& output, const Matrix<t>& M2)
    {
        for (int i = 0; i < M2.row_; i++)
        {
            output << endl;
            for (int j = 0; j < M2.col_; j++)
                output << M2.M[i][j] << "  ";
        }
        output << endl << endl;
        return output;
    }
};
int main()
{
    Matrix<int> matA;
    Matrix<int> matB;
    cout << "Welcome to (Your Name) Matrix Calculator" << endl;
    cout << "------------------------------" << endl;
    cout << "1- Perform Matrix Addition" << endl;
    cout << "2- Perform Matrix Subtraction"<< endl;
    cout << "3- Perform Matrix Multiplication" << endl;
    cout << "4- Matrix Transpose" << endl;
    cout << "5- Exit" << endl;
    int choice;
    cin >> choice;
    switch(choice){
    case 1:
        cout << endl;
        cout << "Addition: " << endl;
        matA + matB;
        break;
    case 2:
        cout << endl;
        cout << "Subtraction:\n" << endl;
        matA - matB;
        break;
    case 3:
        cout << endl;
        cout << "Multiplication:\n" << matA * matB << endl;
        break;
    case 4:
        cout << "Transposed Mat A:" << endl;
        cout << matA.transpose(matA);
        cout << "Transposed Mat B:" << endl;
        cout << matB.transpose(matB);
        break;
    case 5:
        break;
    }
    return 0;
}
