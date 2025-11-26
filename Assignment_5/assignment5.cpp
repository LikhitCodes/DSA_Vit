#include <iostream>
#include <stdlib.h>
using namespace std;

void createSparseMatrix_lac(int **matrix_lac, int n_lac, int m_lac,
                            int *&row_lac, int *&col_lac, int *&val_lac,
                            int &nonZero_lac) {
    nonZero_lac = 0;
    for (int i = 0; i < n_lac; i++)
        for (int j = 0; j < m_lac; j++)
            if (matrix_lac[i][j] != 0)
                nonZero_lac++;

    row_lac = new int[nonZero_lac];
    col_lac = new int[nonZero_lac];
    val_lac = new int[nonZero_lac];

    int idx_lac = 0;
    for (int i = 0; i < n_lac; i++)
        for (int j = 0; j < m_lac; j++)
            if (matrix_lac[i][j] != 0) {
                row_lac[idx_lac] = i;
                col_lac[idx_lac] = j;
                val_lac[idx_lac] = matrix_lac[i][j];
                idx_lac++;
            }
}

void displaySparseMatrix_lac(int *row_lac, int *col_lac, int *val_lac, int nonZero_lac) {
    cout << "Row  Col  Value\n";
    for (int i = 0; i < nonZero_lac; i++)
        cout << row_lac[i] << "    " << col_lac[i] << "    " << val_lac[i] << endl;
    cout << endl;
}

void fastTranspose_lac(int *row_lac, int *col_lac, int *val_lac, int nonZero_lac,
                       int *&t_row_lac, int *&t_col_lac, int *&t_val_lac) {
    if (nonZero_lac == 0) return;

    int maxCol = 0;
    for (int i = 0; i < nonZero_lac; i++)
        if (col_lac[i] > maxCol)
            maxCol = col_lac[i];

    int *count = new int[maxCol + 1]();   
    int *index = new int[maxCol + 1];

    for (int i = 0; i < nonZero_lac; i++)
        count[col_lac[i]]++;

    index[0] = 0;
    for (int i = 1; i <= maxCol; i++)
        index[i] = index[i - 1] + count[i - 1];

    t_row_lac = new int[nonZero_lac];
    t_col_lac = new int[nonZero_lac];
    t_val_lac = new int[nonZero_lac];

    
    for (int i = 0; i < nonZero_lac; i++) {
        int pos = index[col_lac[i]];
        t_row_lac[pos] = col_lac[i];   
        t_col_lac[pos] = row_lac[i];
        t_val_lac[pos] = val_lac[i];
        index[col_lac[i]]++;
    }

    delete[] count;
    delete[] index;
}

int main() {
    int n_lac, m_lac;
    cout << "Enter matrix size n x m: ";
    cin >> n_lac >> m_lac;

    int **matrix_lac = new int*[n_lac];
    for (int i = 0; i < n_lac; i++)
        matrix_lac[i] = new int[m_lac];

    for (int i = 0; i < n_lac; i++)
        for (int j = 0; j < m_lac; j++)
            matrix_lac[i][j] = rand() % 10;  

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < n_lac; i++) {
        for (int j = 0; j < m_lac; j++)
            cout << matrix_lac[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    int *row_lac = nullptr, *col_lac = nullptr, *val_lac = nullptr;
    int nonZero_lac = 0;
    createSparseMatrix_lac(matrix_lac, n_lac, m_lac, row_lac, col_lac, val_lac, nonZero_lac);

    cout << "Sparse Matrix (Triplet form):\n";
    displaySparseMatrix_lac(row_lac, col_lac, val_lac, nonZero_lac);

    int *t_row_lac = nullptr, *t_col_lac = nullptr, *t_val_lac = nullptr;
    fastTranspose_lac(row_lac, col_lac, val_lac, nonZero_lac, t_row_lac, t_col_lac, t_val_lac);

    cout << "Fast Transpose Sparse Matrix:\n";
    displaySparseMatrix_lac(t_row_lac, t_col_lac, t_val_lac, nonZero_lac);

    for (int i = 0; i < n_lac; i++)
        delete[] matrix_lac[i];
    delete[] matrix_lac;
    delete[] row_lac;
    delete[] col_lac;
    delete[] val_lac;
    delete[] t_row_lac;
    delete[] t_col_lac;
    delete[] t_val_lac;

    return 0;
}
