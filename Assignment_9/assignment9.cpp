#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

struct Student_lac {
    string name_lac;
    int roll_lac;
    float marks_lac;
};

void printStudents_lac(Student_lac arr_lac[], int n_lac) {
    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        cout << "Name: " << arr_lac[i_lac].name_lac
             << " | Roll: " << arr_lac[i_lac].roll_lac
             << " | Marks: " << arr_lac[i_lac].marks_lac << endl;
    }
    cout << endl;
}

void bubbleSortStudents_lac(Student_lac arr_lac[], int n_lac) {
    int passCount_lac = 0;
    for (int i_lac = 0; i_lac < n_lac - 1; i_lac++) {
        passCount_lac++;
        cout << "Pass " << passCount_lac << ":" << endl;
        for (int j_lac = 0; j_lac < n_lac - i_lac - 1; j_lac++) {
            if (arr_lac[j_lac].marks_lac < arr_lac[j_lac + 1].marks_lac) {
                cout << "Swapping " << arr_lac[j_lac].name_lac << " (" << arr_lac[j_lac].marks_lac
                     << ") and " << arr_lac[j_lac + 1].name_lac << " (" << arr_lac[j_lac + 1].marks_lac << ")" << endl;
                Student_lac temp_lac = arr_lac[j_lac];
                arr_lac[j_lac] = arr_lac[j_lac + 1];
                arr_lac[j_lac + 1] = temp_lac;
            }
        }
        printStudents_lac(arr_lac, n_lac);
    }

    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        arr_lac[i_lac].roll_lac = i_lac + 1;
    }
}

int main() {
    int n_lac;
    cout << "Enter number of students: ";
    cin >> n_lac;

    srand(time(0));

    Student_lac* students_lac = new Student_lac[n_lac];
    string names_lac[] = {"Likhit", "Sahil", "Rohan", "Pranil", "Prem", "xyz"};

    for (int i_lac = 0; i_lac < n_lac; i_lac++) {
        students_lac[i_lac].name_lac = names_lac[rand() % 5];
        students_lac[i_lac].marks_lac = rand() % 101;
        students_lac[i_lac].roll_lac = 0;
    }

    cout << "\nOriginal List of Students:\n";
    printStudents_lac(students_lac, n_lac);

    cout << "\n--- Bubble Sort Pass-by-Pass Analysis ---\n";
    bubbleSortStudents_lac(students_lac, n_lac);

    cout << "\n--- Final Sorted List with Roll Numbers ---\n";
    printStudents_lac(students_lac, n_lac);

    delete[] students_lac;
    return 0;
}
