#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Student_lac {
    int roll_lac;
    string name_lac;
    int marks_lac;
};

class StudentHash_lac {
    int size_lac;
    vector<list<Student_lac>> table_lac;

public:
    StudentHash_lac(int n_lac = 10) {
        size_lac = n_lac;
        table_lac.assign(size_lac, list<Student_lac>());
    }

    int hash_lac(int roll_lac) {
        return roll_lac % size_lac;
    }

    void insert_lac(Student_lac s_lac) {
        int idx_lac = hash_lac(s_lac.roll_lac);

        for (auto &stu_lac : table_lac[idx_lac]) {
            if (stu_lac.roll_lac == s_lac.roll_lac) {
                cout << "Roll number already exists\n";
                return;
            }
        }

        table_lac[idx_lac].push_back(s_lac);
        cout << "Student inserted\n";
    }

    bool search_lac(int roll_lac, Student_lac &out_lac) {
        int idx_lac = hash_lac(roll_lac);

        for (auto &stu_lac : table_lac[idx_lac]) {
            if (stu_lac.roll_lac == roll_lac) {
                out_lac = stu_lac;
                return true;
            }
        }
        return false;
    }

    bool delete_lac(int roll_lac) {
        int idx_lac = hash_lac(roll_lac);

        for (auto it_lac = table_lac[idx_lac].begin(); it_lac != table_lac[idx_lac].end(); it_lac++) {
            if (it_lac->roll_lac == roll_lac) {
                table_lac[idx_lac].erase(it_lac);
                return true;
            }
        }
        return false;
    }

    void display_lac() {
        cout << "Hash Table (Student Records):\n";
        for (int i_lac = 0; i_lac < size_lac; i_lac++) {
            cout << i_lac << ": ";
            for (auto &stu_lac : table_lac[i_lac]) {
                cout << "[" << stu_lac.roll_lac << ", " << stu_lac.name_lac << ", " << stu_lac.marks_lac << "] -> ";
            }
            cout << "NULL\n";
        }
    }

    void clear_lac() {
        for (int i_lac = 0; i_lac < size_lac; i_lac++)
            table_lac[i_lac].clear();
        cout << "Table cleared\n";
    }
};

int main() {
    int size_lac;
    cout << "Enter hash table size: ";
    cin >> size_lac;

    StudentHash_lac ht_lac(size_lac);

    while (true) {
        cout << "\n1. Insert student\n2. Search student\n3. Delete student\n4. Display table\n5. Clear table\n6. Exit\nEnter choice: ";
        int choice_lac;
        cin >> choice_lac;

        if (choice_lac == 1) {
            Student_lac s_lac;
            cout << "Enter roll number: ";
            cin >> s_lac.roll_lac;
            cout << "Enter name: ";
            cin >> s_lac.name_lac;
            cout << "Enter marks: ";
            cin >> s_lac.marks_lac;

            ht_lac.insert_lac(s_lac);
        }
        else if (choice_lac == 2) {
            int roll_lac;
            cout << "Enter roll number to search: ";
            cin >> roll_lac;

            Student_lac srch_lac;
            if (ht_lac.search_lac(roll_lac, srch_lac)) {
                cout << "Record found: Roll = " << srch_lac.roll_lac 
                     << ", Name = " << srch_lac.name_lac 
                     << ", Marks = " << srch_lac.marks_lac << "\n";
            } else {
                cout << "Record not found\n";
            }
        }
        else if (choice_lac == 3) {
            int roll_lac;
            cout << "Enter roll number to delete: ";
            cin >> roll_lac;

            if (ht_lac.delete_lac(roll_lac)) cout << "Record deleted\n";
            else cout << "Record not found\n";
        }
        else if (choice_lac == 4) {
            ht_lac.display_lac();
        }
        else if (choice_lac == 5) {
            ht_lac.clear_lac();
        }
        else if (choice_lac == 6) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}
