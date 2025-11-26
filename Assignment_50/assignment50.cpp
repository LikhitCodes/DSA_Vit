#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Faculty_lac {
    int id_lac;
    string name_lac;
    string dept_lac;
    string designation_lac;
};

class FacultyHash_lac {
    int size_lac;
    vector<Faculty_lac> table_lac;
    vector<int> state_lac; // 0=empty, 1=occupied, 2=deleted

public:
    FacultyHash_lac(int n_lac = 11) {
        size_lac = n_lac;
        table_lac.assign(size_lac, Faculty_lac{0,"","",""});
        state_lac.assign(size_lac, 0);
    }

    int hash_lac(int id_lac) {
        int idx_lac = id_lac % size_lac;
        if (idx_lac < 0) idx_lac += size_lac;
        return idx_lac;
    }

    bool insert_lac(const Faculty_lac &f_lac) {
        int idx_lac = hash_lac(f_lac.id_lac);
        int start_lac = idx_lac;

        do {
            if (state_lac[idx_lac] == 0 || state_lac[idx_lac] == 2) {
                table_lac[idx_lac] = f_lac;
                state_lac[idx_lac] = 1;
                return true;
            }
            if (state_lac[idx_lac] == 1 && table_lac[idx_lac].id_lac == f_lac.id_lac)
                return false;

            idx_lac = (idx_lac + 1) % size_lac;
        } while (idx_lac != start_lac);

        return false;
    }

    int searchIndex_lac(int id_lac) {
        int idx_lac = hash_lac(id_lac);
        int start_lac = idx_lac;

        do {
            if (state_lac[idx_lac] == 0) return -1;
            if (state_lac[idx_lac] == 1 && table_lac[idx_lac].id_lac == id_lac)
                return idx_lac;

            idx_lac = (idx_lac + 1) % size_lac;
        } while (idx_lac != start_lac);

        return -1;
    }

    Faculty_lac get_lac(int idx_lac) {
        return table_lac[idx_lac];
    }

    bool remove_lac(int id_lac) {
        int pos_lac = searchIndex_lac(id_lac);
        if (pos_lac == -1) return false;

        state_lac[pos_lac] = 2;
        table_lac[pos_lac] = Faculty_lac{0,"","",""};
        return true;
    }

    void display_lac() {
        cout << "Index\tState\t\tFaculty (id, name, dept, designation)\n";
        for (int i_lac = 0; i_lac < size_lac; i_lac++) {
            cout << i_lac << "\t";
            if (state_lac[i_lac] == 0) cout << "Empty\t\t-\n";
            else if (state_lac[i_lac] == 2) cout << "Deleted\t\t-\n";
            else {
                cout << "Occupied\t(" << table_lac[i_lac].id_lac << ", " 
                     << table_lac[i_lac].name_lac << ", " 
                     << table_lac[i_lac].dept_lac << ", " 
                     << table_lac[i_lac].designation_lac << ")\n";
            }
        }
    }

    void autoPopulate_lac() {
        insert_lac(Faculty_lac{100, "ABC", "CSE", "Professor"});
        insert_lac(Faculty_lac{200, "PQR", "ECE", "AssociateProf"});
        insert_lac(Faculty_lac{300, "XYZ", "ME",  "AssistantProf"});
        insert_lac(Faculty_lac{400, "MNO", "CSE", "Lecturer"});
        insert_lac(Faculty_lac{500, "IDK", "IT",  "Professor"});
    }
};

int main() {
    int size_lac;
    cout << "Enter hash table size : ";
    cin >> size_lac;

    FacultyHash_lac ht_lac(size_lac);

    while (true) {
        cout << "\n---- Faculty DB Menu ----\n";
        cout << "1. Insert faculty\n2. Search faculty by ID\n3. Delete faculty by ID\n4. Display table\n5. Auto-populate sample data\n6. Exit\nEnter choice: ";

        int choice_lac;
        cin >> choice_lac;

        if (choice_lac == 1) {
            Faculty_lac f_lac;
            cout << "Enter faculty id: "; cin >> f_lac.id_lac;
            cout << "Enter name: "; cin >> f_lac.name_lac;
            cout << "Enter department: "; cin >> f_lac.dept_lac;
            cout << "Enter designation: "; cin >> f_lac.designation_lac;

            if (ht_lac.insert_lac(f_lac)) cout << "Inserted\n";
            else cout << "Insertion failed\n";
        }
        else if (choice_lac == 2) {
            int id_lac;
            cout << "Enter faculty id to search: ";
            cin >> id_lac;

            int pos_lac = ht_lac.searchIndex_lac(id_lac);
            if (pos_lac == -1) cout << "Faculty not found\n";
            else {
                Faculty_lac f_lac = ht_lac.get_lac(pos_lac);
                cout << "Faculty found at index " << pos_lac << "\n";
                cout << "ID: " << f_lac.id_lac 
                     << ", Name: " << f_lac.name_lac
                     << ", Dept: " << f_lac.dept_lac
                     << ", Designation: " << f_lac.designation_lac << "\n";
            }
        }
        else if (choice_lac == 3) {
            int id_lac;
            cout << "Enter faculty id to delete: ";
            cin >> id_lac;
            cout << (ht_lac.remove_lac(id_lac) ? "Deleted\n" : "Faculty not found\n");
        }
        else if (choice_lac == 4) ht_lac.display_lac();
        else if (choice_lac == 5) { ht_lac.autoPopulate_lac(); cout << "Sample data inserted\n"; }
        else if (choice_lac == 6) break;
        else cout << "Invalid choice\n";
    }
    return 0;
}
