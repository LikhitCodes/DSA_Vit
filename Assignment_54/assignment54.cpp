#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student_lac {
    int roll_lac;
    string name_lac;
    string course_lac;
    int marks_lac;
};

class StudentHash_lac {
public:
    int size_lac;
    vector<Student_lac> table_lac;
    vector<int> state_lac;   // 0=empty, 1=full, 2=deleted

    StudentHash_lac(int n_lac = 10) {
        size_lac = n_lac;
        table_lac.assign(size_lac, Student_lac{0,"","",0});
        state_lac.assign(size_lac, 0);
    }

    int hash_lac(int roll_lac) {
        return roll_lac % size_lac;
    }

    bool insert_lac(Student_lac s) {
        int idx = hash_lac(s.roll_lac);
        int start = idx;

        do {
            if (state_lac[idx] == 0 || state_lac[idx] == 2) {
                table_lac[idx] = s;
                state_lac[idx] = 1;
                return true;
            }
            idx = (idx + 1) % size_lac;
        } while (idx != start);

        return false;
    }

    int search_lac(int roll) {
        int idx = hash_lac(roll);
        int start = idx;

        do {
            if (state_lac[idx] == 0) return -1;
            if (state_lac[idx] == 1 && table_lac[idx].roll_lac == roll)
                return idx;
            idx = (idx + 1) % size_lac;
        } while (idx != start);

        return -1;
    }

    bool delete_lac(int roll) {
        int pos = search_lac(roll);
        if (pos == -1) return false;
        state_lac[pos] = 2;
        table_lac[pos] = Student_lac{0,"","",0};
        return true;
    }

    void display_lac() {
        cout << "\nIndex\tState\tStudent\n";
        for (int i = 0; i < size_lac; i++) {
            cout << i << "\t";
            if (state_lac[i] == 0)
                cout << "Empty\t-\n";
            else if (state_lac[i] == 2)
                cout << "Deleted\t-\n";
            else
                cout << "Full\t(" 
                     << table_lac[i].roll_lac << ", "
                     << table_lac[i].name_lac << ", "
                     << table_lac[i].course_lac << ", "
                     << table_lac[i].marks_lac << ")\n";
        }
    }
};

int main() {
    int size_lac;
    cout << "Enter hash table size: ";
    cin >> size_lac;

    StudentHash_lac ht(size_lac);

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        int ch; cin >> ch;

        if (ch == 1) {
            Student_lac s;
            cout << "Enter Roll No: "; cin >> s.roll_lac;
            cout << "Enter Name: "; cin >> s.name_lac;
            cout << "Enter Course: "; cin >> s.course_lac;
            cout << "Enter Marks: "; cin >> s.marks_lac;
            if (ht.insert_lac(s)) cout << "Inserted\n";
            else cout << "Table Full\n";
        }

        else if (ch == 2) {
            int roll;
            cout << "Enter Roll No: "; cin >> roll;
            int pos = ht.search_lac(roll);
            if (pos == -1)
                cout << "Not found\n";
            else {
                Student_lac s = ht.table_lac[pos];
                cout << "Found at index " << pos << ": "
                     << s.roll_lac << " " << s.name_lac << " "
                     << s.course_lac << " " << s.marks_lac << "\n";
            }
        }

        else if (ch == 3) {
            int roll;
            cout << "Enter Roll No to delete: "; cin >> roll;
            if (ht.delete_lac(roll)) cout << "Deleted\n";
            else cout << "Not found\n";
        }

        else if (ch == 4) ht.display_lac();
        else if (ch == 5) break;
        else cout << "Invalid\n";
    }

    return 0;
}
