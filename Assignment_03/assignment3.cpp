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