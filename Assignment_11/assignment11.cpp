/*
Implementation of Singly Linked List to Manage ‘Vertex Club’ Membership Records.
The Department of Computer Engineering has a student club named ‘Vertex Club’ for second, third, and final year students. The first member is the President and the last member is the Secretary. Write a C++ program to:
●	Add/delete members (including President/Secretary)
●	Count members
●	Display members
●	Concatenate two division lists
 Also implement: reverse, search by PRN, and sort by PRN operations.
*/


#include<iostream>
#include<string>
using namespace std;

typedef struct member_lac {
    unsigned int prn_lac;
    string name_lac;
    struct member_lac *next_lac;
} member_lac;

member_lac *getnode_lac() {
    member_lac *newnode_lac = new member_lac;
    if (newnode_lac == NULL) {
        cout << "getnode_lac(): Memory not allocated!" << endl;
        exit(-1);
    }
    newnode_lac->next_lac = NULL;
    return newnode_lac;
}

member_lac *createList_lac() {
    member_lac *head_lac = getnode_lac();
    head_lac->next_lac = NULL;
    member_lac *temp_lac = head_lac;

    while (1) {
        int ch_lac;
        cout << "Do you want to add a member? (1 for yes / 0 for no): ";
        cin >> ch_lac;
        if (ch_lac == 0)
            break;

        member_lac *cur_lac = getnode_lac();
        cout << "Enter PRN: ";
        cin >> cur_lac->prn_lac;
        cout << "Enter Name: ";
        cin >> cur_lac->name_lac;
        cur_lac->next_lac = NULL;

        temp_lac->next_lac = cur_lac;
        temp_lac = cur_lac;
    }
    return head_lac;
}

void display_lac(member_lac *head_lac) {
    member_lac *temp_lac = head_lac->next_lac;
    cout << "Head -> ";
    while (temp_lac != NULL) {
        cout << "[" << temp_lac->prn_lac << ", " << temp_lac->name_lac << "] -> ";
        temp_lac = temp_lac->next_lac;
    }
    cout << "NULL" << endl << endl;
}

void addPresident_lac(member_lac *head_lac) {
    member_lac *newnode_lac = getnode_lac();
    cout << "Enter President details:" << endl;
    cout << "PRN: ";
    cin >> newnode_lac->prn_lac;
    cout << "Name: ";
    cin >> newnode_lac->name_lac;
    newnode_lac->next_lac = head_lac->next_lac;
    head_lac->next_lac = newnode_lac;
}

void addSecretary_lac(member_lac *head_lac) {
    member_lac *newnode_lac = getnode_lac();
    cout << "Enter Secretary details:" << endl;
    cout << "PRN: ";
    cin >> newnode_lac->prn_lac;
    cout << "Name: ";
    cin >> newnode_lac->name_lac;
    newnode_lac->next_lac = NULL;

    member_lac *temp_lac = head_lac;
    while (temp_lac->next_lac != NULL)
        temp_lac = temp_lac->next_lac;
    temp_lac->next_lac = newnode_lac;
}

void deletePresident_lac(member_lac *head_lac) {
    if (head_lac->next_lac == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    member_lac *temp_lac = head_lac->next_lac;
    head_lac->next_lac = temp_lac->next_lac;
    delete temp_lac;
    cout << "President deleted successfully!" << endl;
}

void deleteSecretary_lac(member_lac *head_lac) {
    if (head_lac->next_lac == NULL) {
        cout << "List empty!" << endl;
        return;
    }
    member_lac *prev_lac = head_lac, *cur_lac = head_lac->next_lac;
    while (cur_lac->next_lac != NULL) {
        prev_lac = cur_lac;
        cur_lac = cur_lac->next_lac;
    }
    prev_lac->next_lac = NULL;
    delete cur_lac;
    cout << "Secretary deleted successfully!" << endl;
}

void countMembers_lac(member_lac *head_lac) {
    int count_lac = 0;
    member_lac *temp_lac = head_lac->next_lac;
    while (temp_lac != NULL) {
        count_lac++;
        temp_lac = temp_lac->next_lac;
    }
    cout << "Total Members: " << count_lac << endl;
}

void search_lac(member_lac *head_lac) {
    unsigned int prn_lac;
    cout << "Enter PRN to search: ";
    cin >> prn_lac;
    member_lac *temp_lac = head_lac->next_lac;
    while (temp_lac != NULL) {
        if (temp_lac->prn_lac == prn_lac) {
            cout << "Member found: " << temp_lac->name_lac << endl;
            return;
        }
        temp_lac = temp_lac->next_lac;
    }
    cout << "Member not found!" << endl;
}

void sort_lac(member_lac *head_lac) {
    if (head_lac->next_lac == NULL) return;
    int swapped_lac;
    member_lac *ptr1_lac;
    member_lac *lptr_lac = NULL;

    do {
        swapped_lac = 0;
        ptr1_lac = head_lac->next_lac;

        while (ptr1_lac->next_lac != lptr_lac) {
            if (ptr1_lac->prn_lac > ptr1_lac->next_lac->prn_lac) {
                swap(ptr1_lac->prn_lac, ptr1_lac->next_lac->prn_lac);
                swap(ptr1_lac->name_lac, ptr1_lac->next_lac->name_lac);
                swapped_lac = 1;
            }
            ptr1_lac = ptr1_lac->next_lac;
        }
        lptr_lac = ptr1_lac;
    } while (swapped_lac);

    cout << "List sorted by PRN successfully!" << endl;
}

void reverse_lac(member_lac *head_lac) {
    member_lac *prev_lac = NULL, *cur_lac = head_lac->next_lac, *next_lac = NULL;
    while (cur_lac != NULL) {
        next_lac = cur_lac->next_lac;
        cur_lac->next_lac = prev_lac;
        prev_lac = cur_lac;
        cur_lac = next_lac;
    }
    head_lac->next_lac = prev_lac;
    cout << "List reversed successfully!" << endl;
}

member_lac *concatenate_lac(member_lac *head1_lac, member_lac *head2_lac) {
    member_lac *temp_lac = head1_lac;
    while (temp_lac->next_lac != NULL)
        temp_lac = temp_lac->next_lac;
    temp_lac->next_lac = head2_lac->next_lac;
    return head1_lac;
}

void deleteList_lac(member_lac *&head_lac) {
    member_lac *temp_lac;
    while (head_lac != NULL) {
        temp_lac = head_lac;
        head_lac = head_lac->next_lac;
        delete temp_lac;
    }
}

int main() {
    cout << "Club management" << endl;
    member_lac *divisionA_lac = NULL, *divisionB_lac = NULL, *merged_lac = NULL;
    divisionA_lac = createList_lac();

    int choice_lac;
    do {
        cout << "\n---- MENU ----" << endl;
        cout << "1) Display Members\n2) Add President\n3) Add Secretary\n4) Delete President\n5) Delete Secretary\n6) Count Members\n7) Search by PRN\n8) Sort by PRN\n9) Reverse List\n10) Concatenate Two Lists\n0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_lac;

        switch (choice_lac) {
        case 1:
            display_lac(divisionA_lac);
            break;
        case 2:
            addPresident_lac(divisionA_lac);
            break;
        case 3:
            addSecretary_lac(divisionA_lac);
            break;
        case 4:
            deletePresident_lac(divisionA_lac);
            break;
        case 5:
            deleteSecretary_lac(divisionA_lac);
            break;
        case 6:
            countMembers_lac(divisionA_lac);
            break;
        case 7:
            search_lac(divisionA_lac);
            break;
        case 8:
            sort_lac(divisionA_lac);
            break;
        case 9:
            reverse_lac(divisionA_lac);
            break;
        case 10:
            cout << "Creating Division B list..." << endl;
            divisionB_lac = createList_lac();
            merged_lac = concatenate_lac(divisionA_lac, divisionB_lac);
            cout << "Lists concatenated successfully!" << endl;
            display_lac(merged_lac);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice_lac != 0);

    deleteList_lac(divisionA_lac);
    deleteList_lac(divisionB_lac);

    return 0;
}
