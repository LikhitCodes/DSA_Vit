# Linear Search on Student Records using Structures

## Name: Likhit Chirmade, Roll no: 23

## Theory

### Structures in C++

A structure is a user-defined data type that groups related data items of different types under a single name. Structures are useful for representing real-world entities with multiple attributes.

**Syntax:**
```cpp
struct structure_name {
    data_type member1;
    data_type member2;
    // ...
};
```

### Linear Search Algorithm

Linear search is a simple searching algorithm that sequentially checks each element in a collection until the target element is found or the entire collection has been searched.

**Algorithm:**
1. Start from the first element
2. Compare each element with the target value
3. If match found, return the position/element
4. If end of array reached without finding target, return "not found"

**Time Complexity:**
- Best Case: O(1) - element found at first position
- Average Case: O(n/2) - element found in middle
- Worst Case: O(n) - element at end or not present

**Space Complexity:** O(1) - no extra space required

### Dynamic Memory Allocation for Structures

In C++, structures can be dynamically allocated using the `new` operator:

```cpp
student_lac *arr = new student_lac[n];    // Allocate array of structures
```

**Accessing Structure Members:**
- Using dot operator: `arr[i].member`
- Using arrow operator (for pointers): `ptr->member`

### C++ Concepts Used

**Structure Declaration:**
```cpp
struct student_lac {
    int roll_lac;
    string name_lac;
};
```

**Dynamic Array of Structures:**
```cpp
student_lac *arr = new student_lac[n];    // Allocate
delete[] arr;                              // Deallocate
```

**NULL Check:**
```cpp
if (arr == NULL)    // Check if memory allocation failed
```

**Boolean Flag:**
```cpp
bool flag = false;    // Used to track if element is found
```

### Application

This program demonstrates:
- Creating a database of student records
- Storing multiple attributes (roll number and name) together
- Searching for a student by roll number using linear search
- Dynamic memory management for structures

## Code

```cpp
#include<iostream>
using namespace std;
#include<string>

struct student_lac {
    int roll_lac;
    string name_lac;
};

int main() { 
    int n_lac;
    cout << "Enter number of students: ";
    cin >> n_lac;

    student_lac *arr = new student_lac[n_lac];

    if (arr == NULL) {
        cout << "Memory not allocated";
    }

    cout << "Enter roll number and name" << endl;
    for (int i = 0; i < n_lac; i++) {
        cin >> arr[i].roll_lac >> arr[i].name_lac;
    }

    int target_lac;
    cout << "Enter roll number you want to search" << endl;
    cin >> target_lac;

    bool flag_lac = false;
    for (int i = 0; i < n_lac; i++) {
        if (arr[i].roll_lac == target_lac) {
            cout << "Student found "
                 << "Name of student: " << arr[i].name_lac << endl;
            flag_lac = true;
        }
    }

    if (flag_lac == false) {
        cout << "Student not found";
    }

    delete[] arr;

    return 0;
}
```

## Output

![1](op1.png)