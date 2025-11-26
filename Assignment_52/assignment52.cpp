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
    vector<int> state_lac;   // 0 = Empty, 1 = Full, 2 = Deleted
    vector<int> next_lac;    // Linked list chain

public:
    vector<Faculty_lac> table_lac;
    FacultyHash_lac(int n_lac = 10) {
        size_lac = n_lac;
        table_lac.assign(size_lac, Faculty_lac{0,"","",""});
        state_lac.assign(size_lac, 0);
        next_lac.assign(size_lac, -1);
    }

    int hash_lac(int id_lac) {
        return id_lac % size_lac;
    }

    int findFree_lac() {
        for (int i = 0; i < size_lac; i++)
            if (state_lac[i] == 0) return i;
        return -1;
    }

    bool insert_lac(Faculty_lac f_lac) {
        int home = hash_lac(f_lac.id_lac);

        if (state_lac[home] == 0) {
            table_lac[home] = f_lac;
            state_lac[home] = 1;
            next_lac[home] = -1;
            return true;
        }

        int homeExisting = hash_lac(table_lac[home].id_lac);

        if (homeExisting != home) {
            Faculty_lac temp = table_lac[home];
            table_lac[home] = f_lac;

            int freeSlot = findFree_lac();
            if (freeSlot == -1) return false;

            table_lac[freeSlot] = temp;
            state_lac[freeSlot] = 1;

            int tempHome = hash_lac(temp.id_lac);
            int cur = tempHome;
            while (next_lac[cur] != -1) cur = next_lac[cur];
            next_lac[cur] = freeSlot;
            next_lac[freeSlot] = -1;
            return true;
        }

        int freeSlot = findFree_lac();
        if (freeSlot == -1) return false;

        table_lac[freeSlot] = f_lac;
        state_lac[freeSlot] = 1;
        next_lac[freeSlot] = -1;

        int cur = home;
        while (next_lac[cur] != -1) cur = next_lac[cur];
        next_lac[cur] = freeSlot;

        return true;
    }

    int search_lac(int id_lac) {
        int home = hash_lac(id_lac);
        int cur = home;

        while (cur != -1) {
            if (state_lac[cur] == 1 && table_lac[cur].id_lac == id_lac)
                return cur;
            cur = next_lac[cur];
        }
        return -1;
    }

    bool delete_lac(int id_lac) {
        int home = hash_lac(id_lac);
        int cur = home, prev = -1;

        while (cur != -1) {
            if (table_lac[cur].id_lac == id_lac && state_lac[cur] == 1) {
                state_lac[cur] = 2;
                table_lac[cur] = Faculty_lac{0,"","",""};
                if (prev != -1) next_lac[prev] = next_lac[cur];
                next_lac[cur] = -1;
                return true;
            }
            prev = cur;
            cur = next_lac[cur];
        }
        return false;
    }

    void display_lac() {
        cout << "\nIndex\tState\tNext\tFaculty\n";
        for (int i = 0; i < size_lac; i++) {
            cout << i << "\t";
            if (state_lac[i] == 0) cout << "Empty\t";
            else if (state_lac[i] == 2) cout << "Del\t";
            else cout << "Full\t";

            cout << next_lac[i] << "\t";

            if (state_lac[i] == 1)
                cout << "(" << table_lac[i].id_lac << ","
                     << table_lac[i].name_lac << ","
                     << table_lac[i].dept_lac << ","
                     << table_lac[i].designation_lac << ")";
            else cout << "-";
            cout << "\n";
        }
    }
};

int main() {
    int size_lac;
    cout << "Enter table size: ";
    cin >> size_lac;

    FacultyHash_lac ht_lac(size_lac);

    while (true) {
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nEnter choice: ";
        int ch; cin >> ch;

        if (ch == 1) {
            Faculty_lac f_lac;
            cout << "Enter ID: "; cin >> f_lac.id_lac;
            cout << "Enter Name: "; cin >> f_lac.name_lac;
            cout << "Enter Dept: "; cin >> f_lac.dept_lac;
            cout << "Enter Designation: "; cin >> f_lac.designation_lac;
            if (ht_lac.insert_lac(f_lac)) cout << "Inserted\n";
            else cout << "Table Full\n";
        }

        else if (ch == 2) {
            int id; cout << "Enter ID: "; cin >> id;
            int pos = ht_lac.search_lac(id);
            if (pos == -1) cout << "Not found\n";
            else {
                Faculty_lac f = ht_lac.table_lac[pos];
                cout << "Found at index " << pos << ": "
                     << f.id_lac << " " << f.name_lac << " "
                     << f.dept_lac << " " << f.designation_lac << "\n";
            }
        }

        else if (ch == 3) {
            int id; cout << "Enter ID: "; cin >> id;
            if (ht_lac.delete_lac(id)) cout << "Deleted\n";
            else cout << "Not found\n";
        }

        else if (ch == 4) ht_lac.display_lac();
        else if (ch == 5) break;
        else cout << "Invalid choice\n";
    }

    return 0;
}
