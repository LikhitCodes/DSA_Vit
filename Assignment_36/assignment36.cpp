#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name_lac;
    int marks_lac;
    Node* left_lac;
    Node* right_lac;
};

Node* createNode(string name_lac, int marks_lac) {
    Node* newNode_lac = new Node();
    newNode_lac->name_lac = name_lac;
    newNode_lac->marks_lac = marks_lac;
    newNode_lac->left_lac = nullptr;
    newNode_lac->right_lac = nullptr;
    return newNode_lac;
}

Node* insert_lac(Node* root_lac, string name_lac, int marks_lac) {
    if (root_lac == nullptr)
        return createNode(name_lac, marks_lac);

    if (marks_lac < root_lac->marks_lac)
        root_lac->left_lac = insert_lac(root_lac->left_lac, name_lac, marks_lac);
    else
        root_lac->right_lac = insert_lac(root_lac->right_lac, name_lac, marks_lac);

    return root_lac;
}

void assignRollNumbers_lac(Node* root_lac, int& roll_lac) {
    if (root_lac == nullptr)
        return;
    assignRollNumbers_lac(root_lac->right_lac, roll_lac); // Higher marks first
    cout << "Roll No: " << roll_lac << " | Name: " << root_lac->name_lac 
         << " | Marks: " << root_lac->marks_lac << endl;
    roll_lac++;
    assignRollNumbers_lac(root_lac->left_lac, roll_lac);
}

int main() {
    Node* root_lac = nullptr;
    int choice_lac;
    string name_lac;
    int marks_lac;

    while (true) {
        cout << "\n--- Student Roll Number Assignment ---\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Display Roll Numbers (Based on Marks)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_lac;

        switch (choice_lac) {
        case 1:
            cout << "Enter Student Name: ";
            cin >> name_lac;
            cout << "Enter Marks: ";
            cin >> marks_lac;
            root_lac = insert_lac(root_lac, name_lac, marks_lac);
            break;
        case 2:
            if (root_lac == nullptr)
                cout << "No records found.\n";
            else {
                cout << "\n--- Roll Numbers Assigned (Topper = Roll No 1) ---\n";
                int roll_lac = 1;
                assignRollNumbers_lac(root_lac, roll_lac);
            }
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
