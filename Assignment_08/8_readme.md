# Quick Sort with Step-by-Step Analysis

## Name: Likhit Chirmade, Roll no: 23

## Theory

### Quick Sort Algorithm

Quick sort is an efficient, divide-and-conquer sorting algorithm that works by selecting a pivot element and partitioning the array around it. Elements smaller than the pivot are moved to its left, and larger elements to its right.

### Working Principle

**Divide and Conquer Strategy:**
1. **Divide**: Select a pivot element and partition the array
2. **Conquer**: Recursively sort the subarrays on both sides of the pivot
3. **Combine**: No explicit combining needed as sorting is done in-place

### Partition Algorithm

The partition function is the core of quick sort:

1. **Select Pivot**: Choose the last element as pivot
2. **Initialize Index**: Set i = low - 1 (index for smaller elements)
3. **Traverse Array**: For each element from low to high-1:
   - If element ≤ pivot, increment i and swap arr[i] with arr[j]
4. **Place Pivot**: Swap arr[i+1] with pivot to place it at correct position
5. **Return**: Return i+1 as the partition index

**Example:**
```
Array: [10, 80, 30, 90, 40, 50, 70]
Pivot: 70 (last element)

Step 1: 10 ≤ 70, i=0, no swap needed
Step 2: 80 > 70, skip
Step 3: 30 ≤ 70, i=1, swap 80 and 30 → [10, 30, 80, 90, 40, 50, 70]
Step 4: 90 > 70, skip
Step 5: 40 ≤ 70, i=2, swap 80 and 40 → [10, 30, 40, 90, 80, 50, 70]
Step 6: 50 ≤ 70, i=3, swap 90 and 50 → [10, 30, 40, 50, 80, 90, 70]
Step 7: Place pivot, swap 80 and 70 → [10, 30, 40, 50, 70, 90, 80]

Partition index: 4 (position of 70)
```

### Recursion in Quick Sort

After partitioning, quick sort recursively sorts:
- Left subarray: elements before partition index
- Right subarray: elements after partition index

**Recursion Tree:**
```
                    [array]
                       |
            ┌──────────┴──────────┐
         [left]              [right]
            |                    |
        ┌───┴───┐            ┌───┴───┐
     [left] [right]       [left] [right]
```

### Time Complexity

- **Best Case**: O(n log n) - balanced partitions
- **Average Case**: O(n log n) - random pivot selection
- **Worst Case**: O(n²) - already sorted array with last element as pivot

### Space Complexity

- **O(log n)**: Recursive call stack space for balanced partitions
- **O(n)**: Worst case when partitions are highly unbalanced

### Advantages

1. In-place sorting (no extra array needed)
2. Cache-friendly due to sequential access
3. Generally faster than other O(n log n) algorithms
4. Efficient for large datasets

### C++ Concepts Used

**Global Variable:**
```cpp
int passCount_lac = 0;    // Tracks number of swaps across function calls
```

**Pass by Reference:**
```cpp
void swap(int &a, int &b)    // Modifies original variables
```

**nothrow Allocation:**
```cpp
int* arr = new(nothrow) int[n];    // Returns nullptr on failure instead of exception
if (!arr) {
    // Handle allocation failure
}
```

**Conditional Operator:**
```cpp
if (!marks_lac)    // Equivalent to: if (marks_lac == nullptr)
```

**Recursive Function:**
```cpp
void quickSort(arr[], low, high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);     // Recursive call
        quickSort(arr, pi + 1, high);    // Recursive call
    }
}
```

## Code

```cpp
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
```

## Output

![1](op1.png)