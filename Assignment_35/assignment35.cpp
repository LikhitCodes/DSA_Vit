/*
    5. Write a Program to create a Binary Tree and perform the following 
       Recursive operations on it:
       a. Inorder Traversal 
       b. Preorder Traversal 
       c. Display Number of Leaf Nodes 
       d. Mirror Image
*/
#include <iostream>
using namespace std;

struct Node_lac {
    int data_lac;
    Node_lac *left_lac, *right_lac;
};

Node_lac* createNode_lac(int val_lac) {
    Node_lac* newNode_lac = new Node_lac();
    newNode_lac->data_lac = val_lac;
    newNode_lac->left_lac = newNode_lac->right_lac = NULL;
    return newNode_lac;
}

// Create tree using user input (recursive)
Node_lac* createTree_lac() {
    int val_lac;
    cout << "Enter node value (-1 for no node): ";
    cin >> val_lac;

    if (val_lac == -1) return NULL;

    Node_lac* root_lac = createNode_lac(val_lac);

    cout << "Enter left child of " << val_lac << ":\n";
    root_lac->left_lac = createTree_lac();

    cout << "Enter right child of " << val_lac << ":\n";
    root_lac->right_lac = createTree_lac();

    return root_lac;
}

// Recursive Inorder: LNR
void inorder_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return;
    inorder_lac(root_lac->left_lac);
    cout << root_lac->data_lac << " ";
    inorder_lac(root_lac->right_lac);
}

// Recursive Preorder: NLR
void preorder_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return;
    cout << root_lac->data_lac << " ";
    preorder_lac(root_lac->left_lac);
    preorder_lac(root_lac->right_lac);
}

// Count leaf nodes (recursive)
int countLeaf_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return 0;

    if (root_lac->left_lac == NULL && root_lac->right_lac == NULL)
        return 1;

    return countLeaf_lac(root_lac->left_lac) +
           countLeaf_lac(root_lac->right_lac);
}

// Mirror tree (swap children recursively)
void mirror_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return;

    mirror_lac(root_lac->left_lac);
    mirror_lac(root_lac->right_lac);

    Node_lac* temp_lac = root_lac->left_lac;
    root_lac->left_lac = root_lac->right_lac;
    root_lac->right_lac = temp_lac;
}

int main() {

    cout << "Create Binary Tree:\n";
    Node_lac* root_lac = createTree_lac();

    cout << "\nInorder Traversal: ";
    inorder_lac(root_lac);

    cout << "\nPreorder Traversal: ";
    preorder_lac(root_lac);

    cout << "\nNumber of Leaf Nodes: " << countLeaf_lac(root_lac);

    mirror_lac(root_lac);

    cout << "\nInorder After Mirror Image: ";
    inorder_lac(root_lac);

    cout << endl;
    return 0;
}
