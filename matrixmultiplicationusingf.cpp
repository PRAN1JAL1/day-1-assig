/*3.Matrix Multiplication Using Function Overloading
Objective
Implement matrix operations in C++ using function overloading. Write a function operate() that can perform:
-	Matrix Addition for matrices of the same dimensions.
-	Matrix Multiplication where the number of columns of the first matrix equals the number of rows of the second matrix.*/
)#include <iostream>
#include <vector>

using namespace std;

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Function for matrix addition
vector<vector<int>> operate(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size();
    int cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return result;
}

// Function for matrix multiplication
vector<vector<int>> operate(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, bool multiply) {
    int rows = mat1.size();
    int cols = mat2[0].size();
    int common = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows, cols;

    // Input for matrix addition
    cout << "Enter the number of rows and columns for addition: ";
    cin >> rows >> cols;

    vector<vector<int>> mat1(rows, vector<int>(cols)), mat2(rows, vector<int>(cols));
    cout << "Enter elements of the first matrix row-wise:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> mat1[i][j];

    cout << "Enter elements of the second matrix row-wise:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> mat2[i][j];

    vector<vector<int>> additionResult = operate(mat1, mat2);
    cout << "Matrix Addition Result:\n";
    displayMatrix(additionResult);

    // Input for matrix multiplication
    int rows1, cols1, rows2, cols2;
    cout << "\nEnter the dimensions of the first matrix for multiplication (rows and columns): ";
    cin >> rows1 >> cols1;

    cout << "Enter the dimensions of the second matrix for multiplication (rows and columns): ";
    cin >> rows2 >> cols2;

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible. Number of columns of the first matrix must equal the number of rows of the second matrix.\n";
        return 1;
    }

    vector<vector<int>> matA(rows1, vector<int>(cols1)), matB(rows2, vector<int>(cols2));
    cout << "Enter elements of the first matrix row-wise:\n";
    for (int i = 0; i < rows1; ++i)
        for (int j = 0; j < cols1; ++j)
            cin >> matA[i][j];

    cout << "Enter elements of the second matrix row-wise:\n";
    for (int i = 0; i < rows2; ++i)
        for (int j = 0; j < cols2; ++j)
            cin >> matB[i][j];

    vector<vector<int>> multiplicationResult = operate(matA, matB, true);
    cout << "Matrix Multiplication Result:\n";
    displayMatrix(multiplicationResult);

    return 0;
}

