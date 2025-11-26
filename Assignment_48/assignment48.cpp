#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable_lac {
    int size_lac;
    vector<list<int>> table_lac;

public:
    HashTable_lac(int n_lac = 10) {
        size_lac = n_lac;
        table_lac.assign(size_lac, list<int>());
    }

    int hash_lac(int key_lac) {
        return key_lac % size_lac;
    }

    void insert_lac(int key_lac) {
        int idx_lac = hash_lac(key_lac);

        for (int x_lac : table_lac[idx_lac])
            if (x_lac == key_lac) {
                cout << "Key already exists\n";
                return;
            }

        table_lac[idx_lac].push_back(key_lac);
        cout << "Inserted\n";
    }

    bool search_lac(int key_lac) {
        int idx_lac = hash_lac(key_lac);
        for (int x_lac : table_lac[idx_lac])
            if (x_lac == key_lac) return true;
        return false;
    }

    bool delete_lac(int key_lac) {
        int idx_lac = hash_lac(key_lac);

        for (auto it_lac = table_lac[idx_lac].begin();
             it_lac != table_lac[idx_lac].end(); it_lac++) {
            if (*it_lac == key_lac) {
                table_lac[idx_lac].erase(it_lac);
                return true;
            }
        }
        return false;
    }

    void display_lac() {
        cout << "Hash Table (Linked List):\n";
        for (int i_lac = 0; i_lac < size_lac; i_lac++) {
            cout << i_lac << ": ";
            for (int x_lac : table_lac[i_lac])
                cout << x_lac << " -> ";
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

    HashTable_lac ht_lac(size_lac);
    int choice_lac;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Clear\n6. Exit\nEnter choice: ";
        cin >> choice_lac;

        if (choice_lac == 1) {
            int key_lac;
            cout << "Enter key: ";
            cin >> key_lac;
            ht_lac.insert_lac(key_lac);
        }
        else if (choice_lac == 2) {
            int key_lac;
            cout << "Enter key to search: ";
            cin >> key_lac;
            if (ht_lac.search_lac(key_lac)) cout << "Key found\n";
            else cout << "Key NOT found\n";
        }
        else if (choice_lac == 3) {
            int key_lac;
            cout << "Enter key to delete: ";
            cin >> key_lac;
            if (ht_lac.delete_lac(key_lac)) cout << "Key deleted\n";
            else cout << "Key NOT found\n";
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
