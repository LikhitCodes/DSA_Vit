#include <iostream>
#include <cstdlib>
using namespace std;

void merge_lac(float arr_lac[], int left_lac, int mid_lac, int right_lac, int &passCount_lac) {
    int n1_lac = mid_lac - left_lac + 1;
    int n2_lac = right_lac - mid_lac;

    float *leftArr_lac = new float[n1_lac];
    float *rightArr_lac = new float[n2_lac];

    for (int i_lac = 0; i_lac < n1_lac; i_lac++) 
    {
        leftArr_lac[i_lac] = arr_lac[left_lac + i_lac];
    }
    for (int j_lac = 0; j_lac < n2_lac; j_lac++) 
    {
        rightArr_lac[j_lac] = arr_lac[mid_lac + 1 + j_lac];
    }

    int i_lac = 0, j_lac = 0, k_lac = left_lac;
    while (i_lac < n1_lac && j_lac < n2_lac)
     {
        if (leftArr_lac[i_lac] <= rightArr_lac[j_lac]) 
        {
            arr_lac[k_lac++] = leftArr_lac[i_lac++];
        }
        else 
        {
            arr_lac[k_lac++] = rightArr_lac[j_lac++];
        }
    }
    while (i_lac < n1_lac) 
    {
        arr_lac[k_lac++] = leftArr_lac[i_lac++];
    }
    while (j_lac < n2_lac) 
    {
        arr_lac[k_lac++] = rightArr_lac[j_lac++];
    }

    cout << "Pass " << passCount_lac++ << ": ";
    for (int x_lac = left_lac; x_lac <= right_lac; x_lac++) 
    {
        cout << arr_lac[x_lac] << " ";
    }
    cout << endl;

    delete[] leftArr_lac;
    delete[] rightArr_lac;
}

void mergeSort_lac(float arr_lac[], int left_lac, int right_lac, int &passCount_lac) {
    if (left_lac < right_lac) {
        int mid_lac = (left_lac + right_lac) / 2;
        mergeSort_lac(arr_lac, left_lac, mid_lac, passCount_lac);
        mergeSort_lac(arr_lac, mid_lac + 1, right_lac, passCount_lac);
        merge_lac(arr_lac, left_lac, mid_lac, right_lac, passCount_lac);
    }
}

int main() {
    int n_lac;
    cout << "Enter number of employees: ";
    cin >> n_lac;

    int *height_lac = new int[n_lac];
    int *weight_lac = new int[n_lac];
    float *average_lac = new float[n_lac];

    cout << "Generated random height and weight:\n";
    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        height_lac[i_lac] = rand() % 61 + 140;
        weight_lac[i_lac] = rand() % 71 + 40;
        average_lac[i_lac] = (height_lac[i_lac] + weight_lac[i_lac]) / 2.0;
        cout << "Emp" << i_lac + 1 << ": " << height_lac[i_lac] << "cm, "
             << weight_lac[i_lac] << "kg -> Avg = " << average_lac[i_lac] << endl;
    }

    int passCount_lac = 1;
    cout << "\n--- Merge Sort Passes ---\n";
    mergeSort_lac(average_lac, 0, n_lac - 1, passCount_lac);

    cout << "\nSorted averages:\n";
    for (int i_lac = 0; i_lac < n_lac; i_lac++) cout << average_lac[i_lac] << " ";

    cout << "\n\nTime Complexity: O(n log n)\n";

    delete[] height_lac;
    delete[] weight_lac;
    delete[] average_lac;

    return 0;
}