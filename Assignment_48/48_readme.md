# Implement collision resolution using linked lists.

## Name: Likhit Chirmade, Roll no: 23

## Theory

### Collision Resolution with Linked Lists

This technique uses linked lists (separate chaining) to handle collisions. Each hash table slot contains a linked list that stores all keys hashing to that index.

### Hash Function

```
h(key) = key mod table_size
```

### Data Structure

```cpp
vector<list<int>> table;
```

- Vector provides array-like access
- List (doubly linked list) stores colliding elements

### Duplicate Prevention

This implementation checks for duplicates before insertion:
```cpp
for (int x : table[idx])
    if (x == key) return; // Duplicate found
```

### Operations

#### Insert with Duplicate Check
```
1. Calculate index = hash(key)
2. Check if key already exists in chain
3. If exists → Reject insertion
4. Else → Append to chain
```

**Time Complexity:** O(chain_length)

#### Search
```
1. Calculate index = hash(key)
2. Traverse linked list at table[index]
3. Return true if key found
```

**Time Complexity:** O(chain_length)

#### Delete
```
1. Calculate index = hash(key)
2. Traverse list using iterator
3. Erase element if found
```

**Time Complexity:** O(chain_length)

#### Clear
```
Clear all linked lists in the table
```

**Time Complexity:** O(n)

### STL List Operations

**Iterator-based deletion:**
```cpp
for (auto it = list.begin(); it != list.end(); it++) {
    if (*it == key) {
        list.erase(it);
        break;
    }
}
```

**Range-based traversal:**
```cpp
for (int x : list) {
    // Process x
}
```

### Advantages

1. **No Duplicates:** Explicit duplicate checking
2. **Dynamic Size:** Chains grow as needed
3. **Simple Deletion:** No state management
4. **Clear Operation:** Easy to reset table

### Time Complexity

| Operation | Average | Worst |
|-----------|---------|-------|
| Insert | O(α) | O(n) |
| Search | O(α) | O(n) |
| Delete | O(α) | O(n) |
| Clear | O(n) | O(n) |

where α = load factor (n/m)

### Space Complexity

O(n + m) for n elements and m table size

## Code

```cpp
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
        cout << "Hash Table (Separate Chaining):\n";
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
```

## Output

*[Placeholder for program output screenshot]*
