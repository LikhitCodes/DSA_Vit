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
public:
    int size_lac;
    vector<Faculty_lac> table_lac;
    vector<int> state_lac; // 0 = empty, 1 = full, 2 = deleted

    FacultyHash_lac(int n_lac = 10) {
        size_lac = n_lac;
        table_lac.assign(size_lac, Faculty_lac{0,"","",""});
        state_lac.assign(size_lac, 0);
    }

    int hash_lac(int id_lac) {
        return id_lac % size_lac;
    }

    bool insert_lac(Faculty_lac f_lac) {
        int idx_lac = hash_lac(f_lac.id_lac);
        int start_lac = idx_lac;

        do {
            if (state_lac[idx_lac] == 0 || state_lac[idx_lac] == 2) { 
                table_lac[idx_lac] = f_lac;
                state_lac[idx_lac] = 1;
                return true;
            }
            idx_lac = (idx_lac + 1) % size_lac;
        } while (idx_lac != start_lac);

        return false;
    }

    int search_lac(int id_lac) {
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

    bool delete_lac(int id_lac) {
        int pos_lac = search_lac(id_lac);
        if (pos_lac == -1) return false;

        state_lac[pos_lac] = 2;
        table_lac[pos_lac] = Faculty_lac{0,"","",""};
        return true;
    }

    void display_lac() {
        cout << "\nIndex\tState\tFaculty\n";
        for (int i_lac = 0; i_lac < size_lac; i_lac++) {
            cout << i_lac << "\t";
            if (state_lac[i_lac] == 0)
                cout << "Empty\t-\n";
            else if (state_lac[i_lac] == 2)
                cout << "Deleted\t-\n";
            else
                cout << "Full\t(" 
                     << table_lac[i_lac].id_lac << ", "
                     << table_lac[i_lac].name_lac << ", "
                     << table_lac[i_lac].dept_lac << ", "
                     << table_lac[i_lac].designation_lac 
                     << ")\n";
        }
    }
};

int main() {
    int size_lac;
    cout << "Enter hash table size: ";
    cin >> size_lac;

    FacultyHash_lac ht_lac(size_lac);

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Delete Faculty\n";
        cout << "4. Display Table\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        int ch_lac;
        cin >> ch_lac;

        if (ch_lac == 1) {
            Faculty_lac f_lac;
            cout << "Enter ID: "; cin >> f_lac.id_lac;
            cout << "Enter Name: "; cin >> f_lac.name_lac;
            cout << "Enter Dept: "; cin >> f_lac.dept_lac;
            cout << "Enter Designation: "; cin >> f_lac.designation_lac;

            if (ht_lac.insert_lac(f_lac)) cout << "Inserted Successfully\n";
            else cout << "Table Full\n";
        }
        else if (ch_lac == 2) {
            int id_lac;
            cout << "Enter ID to search: ";
            cin >> id_lac;

            int pos_lac = ht_lac.search_lac(id_lac);
            if (pos_lac == -1) cout << "Not Found\n";
            else {
                Faculty_lac f_lac = ht_lac.table_lac[pos_lac];
                cout << "Found at index " << pos_lac << ": "
                     << f_lac.id_lac << " " << f_lac.name_lac << " " 
                     << f_lac.dept_lac << " " << f_lac.designation_lac << "\n";
            }
        }
        else if (ch_lac == 3) {
            int id_lac;
            cout << "Enter ID to delete: ";
            cin >> id_lac;

            if (ht_lac.delete_lac(id_lac)) cout << "Deleted\n";
            else cout << "Not Found\n";
        }
        else if (ch_lac == 4) ht_lac.display_lac();
        else if (ch_lac == 5) break;
        else cout << "Invalid Choice\n";
    }

    return 0;
}
