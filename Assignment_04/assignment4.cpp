#include<iostream>
#include<stdlib.h>
using namespace std;

void printMatrix_lac(int **matrix_lac, int n_lac,int m_lac) {
    for(int i=0;i<n_lac;i++) {
        for(int j=0;j<m_lac;j++) {
            cout<<matrix_lac[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void createSparseMatrix_lac(int **matrix_lac, int n_lac, int m_lac, int *&row_lac, int *&col_lac, int *&val_lac, int &nonZero_lac) {
    nonZero_lac = 0;
    for(int i=0;i<n_lac;i++)
    {
        for(int j=0;j<m_lac;j++)
        {
            if(matrix_lac[i][j]!=0)
            {
                nonZero_lac++;
            }
        }
    }

    row_lac = new int[nonZero_lac];
    col_lac = new int[nonZero_lac];
    val_lac = new int[nonZero_lac];

    int idx_lac = 0;
    for(int i=0;i<n_lac;i++)
    {
        for(int j=0;j<m_lac;j++)
        {
            if(matrix_lac[i][j]!=0) {
                row_lac[idx_lac] = i;
                col_lac[idx_lac] = j;
                val_lac[idx_lac] = matrix_lac[i][j];
                idx_lac++;
            }
        }
    }
}

void displaySparseMatrix_lac(int *row_lac, int *col_lac, int *val_lac, int nonZero_lac) {
    cout << "Row  Col  Value\n";
    for(int i=0;i<nonZero_lac;i++)
        cout << row_lac[i] << "    " << col_lac[i] << "    " << val_lac[i] << endl;
    cout << endl;
}

void transposeSparseMatrix_lac(int *row_lac, int *col_lac, int *val_lac, int nonZero_lac) {
    for(int i=0;i<nonZero_lac;i++) {
        int temp = row_lac[i];
        row_lac[i] = col_lac[i];
        col_lac[i] = temp;
    }
}

int main() {
    int n_lac, m_lac;
    int *row_lac=nullptr, *col_lac=nullptr, *val_lac=nullptr;
    int nonZero_lac = 0;

    cout << "Enter size n x m matrix: ";
    cin >> n_lac >> m_lac;

    int **matrix_lac = new int*[n_lac];
    for(int i=0;i<n_lac;i++)
        matrix_lac[i] = new int[m_lac];

    for(int i=0;i<n_lac;i++)
        for(int j=0;j<m_lac;j++)
            matrix_lac[i][j] = rand()%10;

    cout << "\nOriginal Matrix:\n";
    printMatrix_lac(matrix_lac,n_lac,m_lac);

    createSparseMatrix_lac(matrix_lac, n_lac, m_lac, row_lac, col_lac, val_lac, nonZero_lac);

    cout << "Sparse Matrix Representation:\n";
    displaySparseMatrix_lac(row_lac, col_lac, val_lac, nonZero_lac);

    transposeSparseMatrix_lac(row_lac, col_lac, val_lac, nonZero_lac);
    cout << "Transpose of Sparse Matrix:\n";
    displaySparseMatrix_lac(row_lac, col_lac, val_lac, nonZero_lac);

    for(int i=0;i<n_lac;i++)
        delete[] matrix_lac[i];
    delete[] matrix_lac;
    delete[] row_lac;
    delete[] col_lac;
    delete[] val_lac;

    return 0;
}