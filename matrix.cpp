#include <iostream>
#include <vector>

using namespace std;

void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    cout << "행렬의 값을 입력하세요:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, vector<vector<int>>& result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "행렬의 행과 열의 크기를 입력하세요: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix1(rows, vector<int>(cols));
    vector<vector<int>> matrix2(rows, vector<int>(cols));
    vector<vector<int>> result(rows, vector<int>(cols));

    cout << "첫 번째 행렬 입력:" << endl;
    inputMatrix(matrix1, rows, cols);

    cout << "두 번째 행렬 입력:" << endl;
    inputMatrix(matrix2, rows, cols);

    addMatrices(matrix1, matrix2, result, rows, cols);

    cout << "두 행렬의 합:" << endl;
    printMatrix(result, rows, cols);

    return 0;
}

