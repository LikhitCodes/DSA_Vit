# Matrix Multiplication - Row-Major vs Column-Major Order

## Name: Likhit Chirmade, Roll no: 23

## Theory

### Matrix Multiplication

Matrix multiplication is a binary operation that takes two matrices and produces a third matrix. For two matrices A (m×n) and B (n×p), the resulting matrix C (m×p) is computed as:

**C[i][j] = Σ(A[i][k] × B[k][j])** for k = 0 to n-1

Each element C[i][j] is the dot product of the i-th row of matrix A and the j-th column of matrix B.

### Row-Major vs Column-Major Order

Memory layout and access patterns significantly impact performance in matrix operations:

#### Row-Major Order
- **Memory Layout**: Elements are stored row by row in contiguous memory
- **Access Pattern**: Traverse outer loop by rows (i), then columns (j)
- **Cache Efficiency**: Better cache locality when accessing consecutive elements in a row
- **Formula**: `C[i][j] += A[i][k] * B[k][j]`

#### Column-Major Order
- **Memory Layout**: Elements are stored column by column
- **Access Pattern**: Traverse outer loop by columns (j), then rows (i)
- **Cache Efficiency**: Better when processing columns sequentially
- **Formula**: `C[j][i] += A[j][k] * B[k][i]`

### C++ Implementation Details

**Dynamic 2D Array Allocation:**
```cpp
int **matrix = new int*[n];      // Allocate array of pointers
for(int i = 0; i < n; i++)
    matrix[i] = new int[n];      // Allocate each row
```

**Memory Deallocation:**
```cpp
for(int i = 0; i < n; i++)
    delete[] matrix[i];          // Delete each row
delete[] matrix;                 // Delete pointer array
```

**Random Number Generation:**
```cpp
rand() % 10 + 1                  // Generates random numbers from 1 to 10
```

### Algorithm Complexity

- **Time Complexity**: O(n³) for both row-major and column-major approaches
- **Space Complexity**: O(n²) for storing three n×n matrices
- **Cache Performance**: Row-major order typically performs better in C/C++ due to row-wise memory layout

## Code

```cpp
#include <iostream>
#include<stdlib.h>
using namespace std;

void printMatrix_lac(int **matrix_lac, int n_lac) {
    for(int i=0;i<n_lac;i++){
        for(int j=0;j<n_lac;j++)
            cout<<matrix_lac[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void multiplyRowMajor_lac(int **A_lac, int **B_lac, int **C_lac, int n_lac) {
    for(int i_lac=0;i_lac<n_lac;i_lac++)
    {
        for(int j_lac=0;j_lac<n_lac;j_lac++)
        {
            C_lac[i_lac][j_lac]=0;
            for(int k_lac=0;k_lac<n_lac;k_lac++)
            {
                C_lac[i_lac][j_lac]+=A_lac[i_lac][k_lac]*B_lac[k_lac][j_lac];
            }
        }
    }     
}

void multiplyColumnMajor_lac(int **A_lac, int **B_lac, int **C_lac, int n_lac) 
{
    for(int i_lac=0;i_lac<n_lac;i_lac++)
    {
        for(int j_lac=0;j_lac<n_lac;j_lac++)
        {
            C_lac[j_lac][i_lac]=0;
            for(int k_lac=0;k_lac<n_lac;k_lac++)
            {
                C_lac[j_lac][i_lac]+=A_lac[j_lac][k_lac]*B_lac[k_lac][i_lac]; 
            }
               
        }
    }
        
}

int main() {
    int n_lac;
    cout << "Enter size n for n x n matrices: ";
    cin >> n_lac;

    int **A_lac = new int*[n_lac];
    int **B_lac = new int*[n_lac];
    int **C_lac = new int*[n_lac];

    for(int i=0;i<n_lac;i++){
        A_lac[i] = new int[n_lac];
        B_lac[i] = new int[n_lac];
        C_lac[i] = new int[n_lac];
    }

    for(int i=0;i<n_lac;i++)
        for(int j=0;j<n_lac;j++){
            A_lac[i][j] = rand()%10 + 1;
            B_lac[i][j] = rand()%10 + 1;
        }

    cout << "\nMatrix A:\n"; 
    printMatrix_lac(A_lac,n_lac);

    cout << "\nMatrix B:\n"; 
    printMatrix_lac(B_lac,n_lac);

    
    multiplyRowMajor_lac(A_lac,B_lac,C_lac,n_lac);
    cout << "\nRow-Major Result Matrix:\n"; printMatrix_lac(C_lac,n_lac);
   
    
    multiplyColumnMajor_lac(A_lac,B_lac,C_lac,n_lac);
    cout << "\nColumn-Major-like Result Matrix:\n"; printMatrix_lac(C_lac,n_lac);
    
    for(int i=0;i<n_lac;i++){
        delete[] A_lac[i];
        delete[] B_lac[i];
        delete[] C_lac[i];
    }
    delete[] A_lac; delete[] B_lac; delete[] C_lac;

    return 0;
}
```

## Output

![1](op1.png)
