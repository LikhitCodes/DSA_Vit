/*
	4 Write a Program to create a Binary Tree and perform following Nonrecursive 
    operations on it. 
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
    Node_lac* newNode_lac = new Node_lac;
    newNode_lac->data_lac = val_lac;
    newNode_lac->left_lac = newNode_lac->right_lac = NULL;
    return newNode_lac;
}
struct Stack_lac {
    Node_lac* arr_lac[50];
    int top_lac;
    Stack_lac() { top_lac = -1; }
    void push_lac(Node_lac* n_lac) { arr_lac[++top_lac] = n_lac; }
    Node_lac* pop_lac() { return arr_lac[top_lac--]; }
    bool isEmpty_lac() { return top_lac == -1; }
};
struct Queue_lac {
    Node_lac* arr_lac[50];
    int front_lac, rear_lac;
    Queue_lac() { front_lac = rear_lac = -1; }

    void enqueue_lac(Node_lac* n_lac) {
        if (rear_lac == 49) return;
        if (front_lac == -1) front_lac = 0;
        arr_lac[++rear_lac] = n_lac;
    }
    Node_lac* dequeue_lac() {
        if (front_lac == -1 || front_lac > rear_lac) return NULL;
        return arr_lac[front_lac++];
    }
    bool isEmpty_lac() {
        return (front_lac == -1 || front_lac > rear_lac);
    }
};
Node_lac* createTree_lac() {
    int val_lac;
    cout << "Enter data for root (-1 for no node): ";
    cin >> val_lac;

    if (val_lac == -1) return NULL;

    Node_lac* root_lac = createNode_lac(val_lac);
    Queue_lac q_lac;
    q_lac.enqueue_lac(root_lac);

    while (!q_lac.isEmpty_lac()) {
        Node_lac* current_lac = q_lac.dequeue_lac();

        cout << "Enter left child of " << current_lac->data_lac << " (-1 for no node): ";
        cin >> val_lac;
        if (val_lac != -1) {
            current_lac->left_lac = createNode_lac(val_lac);
            q_lac.enqueue_lac(current_lac->left_lac);
        }

        cout << "Enter right child of " << current_lac->data_lac << " (-1 for no node): ";
        cin >> val_lac;
        if (val_lac != -1) {
            current_lac->right_lac = createNode_lac(val_lac);
            q_lac.enqueue_lac(current_lac->right_lac);
        }
    }
    return root_lac;
}

void inorderNonRecursive_lac(Node_lac* root_lac) {
    Stack_lac s_lac;
    Node_lac* curr_lac = root_lac;

    while (curr_lac != NULL || !s_lac.isEmpty_lac()) {
        while (curr_lac != NULL) {
            s_lac.push_lac(curr_lac);
            curr_lac = curr_lac->left_lac;
        }
        curr_lac = s_lac.pop_lac();
        cout << curr_lac->data_lac << " ";
        curr_lac = curr_lac->right_lac;
    }
}

void preorderNonRecursive_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return;
    Stack_lac s_lac;
    s_lac.push_lac(root_lac);

    while (!s_lac.isEmpty_lac()) {
        Node_lac* node_lac = s_lac.pop_lac();
        cout << node_lac->data_lac << " ";

        if (node_lac->right_lac) s_lac.push_lac(node_lac->right_lac);
        if (node_lac->left_lac)  s_lac.push_lac(node_lac->left_lac);
    }
}

int countLeafNodes_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return 0;

    int count_lac = 0;
    Stack_lac s_lac;
    s_lac.push_lac(root_lac);

    while (!s_lac.isEmpty_lac()) {
        Node_lac* node_lac = s_lac.pop_lac();

        if (node_lac->left_lac == NULL && node_lac->right_lac == NULL)
            count_lac++;

        if (node_lac->right_lac) s_lac.push_lac(node_lac->right_lac);
        if (node_lac->left_lac)  s_lac.push_lac(node_lac->left_lac);
    }
    return count_lac;
}

void mirrorTree_lac(Node_lac* root_lac) {
    if (root_lac == NULL) return;

    Stack_lac s_lac;
    s_lac.push_lac(root_lac);

    while (!s_lac.isEmpty_lac()) {
        Node_lac* node_lac = s_lac.pop_lac();

        Node_lac* temp_lac = node_lac->left_lac;
        node_lac->left_lac = node_lac->right_lac;
        node_lac->right_lac = temp_lac;

        if (node_lac->left_lac) s_lac.push_lac(node_lac->left_lac);
        if (node_lac->right_lac) s_lac.push_lac(node_lac->right_lac);
    }
}

int main() {
    Node_lac* root_lac = createTree_lac();

    cout << "\nInorder Traversal: ";
    inorderNonRecursive_lac(root_lac);

    cout << "\nPreorder Traversal: ";
    preorderNonRecursive_lac(root_lac);

    cout << "\nNumber of Leaf Nodes: " << countLeafNodes_lac(root_lac);

    mirrorTree_lac(root_lac);

    cout << "\nInorder of Mirror Tree: ";
    inorderNonRecursive_lac(root_lac);

    return 0;
}