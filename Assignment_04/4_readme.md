# Sparse Matrix Representation and Transpose

## Name: Likhit Chirmade, Roll no: 23

## Theory

### Sparse Matrix

A sparse matrix is a matrix in which most of the elements are zero. Storing such matrices in their normal form wastes a lot of memory space. A sparse matrix representation stores only the non-zero elements along with their positions, significantly reducing memory usage.

**Example:**
```
Normal Matrix (4x5):        Memory: 20 elements
0  0  3  0  4
0  0  5  7  0
0  0  0  0  0
0  2  6  0  0

Sparse Representation:      Memory: 5 non-zero elements
Row  Col  Value
0    2    3
0    4    4
1    2    5
1    3    7
3    1    2
```

### Sparse Matrix Representation Methods

This program uses the **Coordinate List (COO)** format, which stores three arrays:
- **Row array**: Stores row indices of non-zero elements
- **Column array**: Stores column indices of non-zero elements
- **Value array**: Stores the actual non-zero values

### Advantages of Sparse Matrix Representation

1. **Memory Efficiency**: Only stores non-zero elements
2. **Computational Efficiency**: Operations skip zero elements
3. **Space Complexity**: O(k) where k = number of non-zero elements, instead of O(n×m)

### Transpose of Sparse Matrix

Transposing a sparse matrix in COO format is simple: swap the row and column indices for each non-zero element.

**Algorithm:**
```
For each non-zero element:
    Swap(row[i], col[i])
```

This operation has O(k) time complexity where k is the number of non-zero elements.

### C++ Concepts Used

**Pass by Reference for Pointers:**
```cpp
int *&row_lac    // Reference to pointer, allows modification of pointer itself
```

**Nullptr Initialization:**
```cpp
int *ptr = nullptr;    // Safe pointer initialization
```

**Dynamic Array Allocation:**
```cpp
row_lac = new int[nonZero_lac];    // Allocate array based on non-zero count
```

**Memory Deallocation:**
```cpp
delete[] row_lac;    // Free dynamically allocated array
```

## Code

```cpp
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
```

## Output

![1](op1.png)
