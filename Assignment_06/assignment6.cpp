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
