#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int passCount_lac = 0;

void swap_lac(int &a_lac, int &b_lac) {
    int temp_lac = a_lac;
    a_lac = b_lac;
    b_lac = temp_lac;
}

void printArray_lac(int arr_lac[], int n_lac) {
    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        cout << arr_lac[i_lac] << " ";
    }
    cout << endl;
}

int partition_lac(int arr_lac[], int low_lac, int high_lac, int n_lac) {
    int pivot_lac = arr_lac[high_lac];
    int i_lac = low_lac - 1;

    for (int j_lac = low_lac; j_lac < high_lac; j_lac++) {
        if (arr_lac[j_lac] <= pivot_lac) {
            i_lac++;
            if (i_lac != j_lac) {
                passCount_lac++;
                cout << "Pass " << passCount_lac << ": Swapped " 
                     << arr_lac[i_lac] << " and " << arr_lac[j_lac] << " -> ";
                swap_lac(arr_lac[i_lac], arr_lac[j_lac]);
                printArray_lac(arr_lac, n_lac);
            }
        }
    }

    if (i_lac + 1 != high_lac) {
        passCount_lac++;
        cout << "Pass " << passCount_lac << ": Swapped " 
             << arr_lac[i_lac + 1] << " and " << arr_lac[high_lac] << " -> ";
        swap_lac(arr_lac[i_lac + 1], arr_lac[high_lac]);
        printArray_lac(arr_lac, n_lac);
    }

    return i_lac + 1;
}

void quickSort_lac(int arr_lac[], int low_lac, int high_lac, int n_lac) {
    if (low_lac < high_lac) {
        int pi_lac = partition_lac(arr_lac, low_lac, high_lac, n_lac);
        quickSort_lac(arr_lac, low_lac, pi_lac - 1, n_lac);
        quickSort_lac(arr_lac, pi_lac + 1, high_lac, n_lac);
    }
}

int main() {
    srand(time(0));
    int n_lac;
    cout << "Enter number of students: ";
    cin >> n_lac;

    int* marks_lac = new(nothrow) int[n_lac];
    if (!marks_lac) {
        cout << "Memory allocation failed!\n";
        return 1;
    }

    cout << "\nOriginal Marks: ";
    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        marks_lac[i_lac] = rand() % 100 + 1;
        cout << marks_lac[i_lac] << " ";
    }
    cout << "\n\n--- Quick Sort Analysis ---\n";

    quickSort_lac(marks_lac, 0, n_lac - 1, n_lac);

    cout << "\nFinal Sorted Marks: ";
    printArray_lac(marks_lac, n_lac);

    cout << "Total passes required: " << passCount_lac << endl;

    delete[] marks_lac;
    return 0;
}