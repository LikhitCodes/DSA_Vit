#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Product_lac {
    int code_lac;
    string name_lac;
    float price_lac;
    int quantity_lac;
    string dateReceived_lac;
    string expirationDate_lac;
    Product_lac *left_lac, *right_lac;
};

bool isExpired_lac(const string &expiry_lac, const string &current_lac) {
    return expiry_lac < current_lac;
}

Product_lac* createProduct_lac() {
    Product_lac* new_lac = new Product_lac();

    cout << "\nEnter Product Code: ";
    cin >> new_lac->code_lac;
    cin.ignore();

    cout << "Enter Product Name: ";
    getline(cin, new_lac->name_lac);

    cout << "Enter Price: ";
    cin >> new_lac->price_lac;

    cout << "Enter Quantity in Stock: ";
    cin >> new_lac->quantity_lac;
    cin.ignore();

    cout << "Enter Date Received (YYYY-MM-DD): ";
    getline(cin, new_lac->dateReceived_lac);

    cout << "Enter Expiration Date (YYYY-MM-DD): ";
    getline(cin, new_lac->expirationDate_lac);

    new_lac->left_lac = new_lac->right_lac = nullptr;
    return new_lac;
}

Product_lac* insert_lac(Product_lac* root_lac, Product_lac* new_lac) {
    if (!root_lac)
        return new_lac;
    if (new_lac->code_lac < root_lac->code_lac)
    root_lac->left_lac = insert_lac(root_lac->left_lac, new_lac);
    else if (new_lac->code_lac > root_lac->code_lac)
    root_lac->right_lac = insert_lac(root_lac->right_lac, new_lac);

    else
        cout << "Duplicate product name not allowed.\n";
    return root_lac;
}

void inorder_lac(Product_lac* root_lac) {
    if (root_lac) {
        inorder_lac(root_lac->left_lac);
        cout << "Code: " << root_lac->code_lac << ", Name: " << root_lac->name_lac
             << ", Price: " << root_lac->price_lac << ", Quantity: " << root_lac->quantity_lac
             << ", Expiry: " << root_lac->expirationDate_lac << endl;
        inorder_lac(root_lac->right_lac);
    }
}

Product_lac* findMin_lac(Product_lac* node_lac) {
    while (node_lac && node_lac->left_lac)
        node_lac = node_lac->left_lac;
    return node_lac;
}

Product_lac* deleteByCode_lac(Product_lac* root_lac, int code_lac) {
    if (!root_lac) return nullptr;

    if (code_lac < root_lac->code_lac)
        root_lac->left_lac = deleteByCode_lac(root_lac->left_lac, code_lac);
    else if (code_lac > root_lac->code_lac)
        root_lac->right_lac = deleteByCode_lac(root_lac->right_lac, code_lac);
    else {
        if (!root_lac->left_lac) {
            Product_lac* temp = root_lac->right_lac;
            delete root_lac;
            return temp;
        } 
        else if (!root_lac->right_lac) {
            Product_lac* temp = root_lac->left_lac;
            delete root_lac;
            return temp;
        }

        Product_lac* temp = findMin_lac(root_lac->right_lac);
        root_lac->code_lac = temp->code_lac;
        root_lac->name_lac = temp->name_lac;
        root_lac->price_lac = temp->price_lac;
        root_lac->quantity_lac = temp->quantity_lac;
        root_lac->dateReceived_lac = temp->dateReceived_lac;
        root_lac->expirationDate_lac = temp->expirationDate_lac;

        root_lac->right_lac = deleteByCode_lac(root_lac->right_lac, temp->code_lac);
    }
    return root_lac;
}

Product_lac* deleteExpired_lac(Product_lac* root_lac, const string &current_lac) {
    if (!root_lac) return nullptr;

    root_lac->left_lac = deleteExpired_lac(root_lac->left_lac, current_lac);
    root_lac->right_lac = deleteExpired_lac(root_lac->right_lac, current_lac);

    if (isExpired_lac(root_lac->expirationDate_lac, current_lac)) {
        cout << "Deleting expired product: " << root_lac->name_lac << endl;
        root_lac = deleteByCode_lac(root_lac, root_lac->code_lac);
    }
    return root_lac;
}

int main() {
    Product_lac* root_lac = nullptr;
    int choice_lac;

    while (true) {
        cout << "\n--- Product Inventory Management ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. Delete Product by Code\n";
        cout << "4. Delete All Expired Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_lac;

        switch (choice_lac) {
            case 1: {
                Product_lac* p_lac = createProduct_lac();
                root_lac = insert_lac(root_lac, p_lac);
                break;
            }
            case 2:
                cout << "\nAll Products:\n";
                inorder_lac(root_lac);
                break;

            case 3: {
                int code_lac;
                cout << "\nEnter Product Code to Delete: ";
                cin >> code_lac;
                root_lac = deleteByCode_lac(root_lac, code_lac);
                break;
            }

            case 4: {
                string current_lac;
                cout << "\nEnter Current Date (YYYY-MM-DD): ";
                cin.ignore();
                getline(cin, current_lac);
                root_lac = deleteExpired_lac(root_lac, current_lac);
                break;
            }

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
