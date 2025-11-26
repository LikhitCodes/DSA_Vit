#include<iostream>
#include<math.h>
using namespace std;

typedef struct mylist_lac
{
    int seatNo_lac;
    bool isBooked_lac;
    mylist_lac *next_lac;
    mylist_lac *prev_lac;
} mylist_lac;

mylist_lac *rows_lac[8];

void createList_lac(mylist_lac *head_lac)
{
    head_lac->next_lac = head_lac;
    head_lac->prev_lac = head_lac;
    mylist_lac *last_lac = head_lac;

    for (int i_lac = 1; i_lac <= 8; i_lac++)
    {
        mylist_lac *node_lac = new mylist_lac;
        node_lac->seatNo_lac = i_lac;
        int x_lac = rand() % 2;
        node_lac->isBooked_lac = (x_lac ? true : false);

        node_lac->prev_lac = last_lac;
        last_lac->next_lac = node_lac;
        node_lac->next_lac = head_lac;
        head_lac->prev_lac = node_lac;

        last_lac = node_lac;
    }
}

void createArray_lac()
{
    for (int i_lac = 0; i_lac < 8; i_lac++)
    {
        mylist_lac *head_lac = new mylist_lac;
        head_lac->next_lac = nullptr;
        head_lac->prev_lac = nullptr;
        rows_lac[i_lac] = head_lac;
        createList_lac(head_lac);
    }
}

void DisplayAvailableSeats_lac()
{
    cout << "\n=========== Seatings ===========\n";
    cout << "Seats ->  1  2  3  4  5  6  7  8\n";
    cout << "            -----------------------\n";

    for (int i_lac = 0; i_lac < 8; i_lac++)
    {
        mylist_lac *head_lac = rows_lac[i_lac];
        mylist_lac *temp_lac = head_lac->next_lac;

        cout << "Row " << i_lac + 1 << "  |  ";

        while (temp_lac != head_lac)
        {
            if (temp_lac->isBooked_lac == false)
            {
                cout << "O  ";     
            }
            else 
            {
                cout << "X  ";     
            }

            temp_lac = temp_lac->next_lac;
        }
        cout << endl;
    }

    cout << "\nLegend ->  O = Available   X = Booked\n";
    cout << "==================================================\n";
}


void BookSeat_lac(int r_lac, int s_lac)
{
    mylist_lac *head_lac = rows_lac[r_lac - 1];
    mylist_lac *temp_lac = head_lac->next_lac;
    for (int i_lac = 1; i_lac < s_lac; i_lac++)
    {
        temp_lac = temp_lac->next_lac;
    }
    if (temp_lac->isBooked_lac)
    {
        cout << "Seat already booked" << endl;
    }
    else
    {
        temp_lac->isBooked_lac = true;
        cout << "The seat no. " << s_lac << " at row " << r_lac << " is booked now." << endl;
    }
}

void CancelSeat_lac(int r_lac, int s_lac)
{
    mylist_lac *head_lac = rows_lac[r_lac - 1];
    mylist_lac *temp_lac = head_lac->next_lac;
    for (int i_lac = 1; i_lac < s_lac; i_lac++)
    {
        temp_lac = temp_lac->next_lac;
    }
    if (temp_lac->isBooked_lac)
    {
        temp_lac->isBooked_lac = false;
        cout << "The seat no. " << s_lac << " at row " << r_lac << " is cancelled now." << endl;
    }
    else
    {
        cout << "The seat no. " << s_lac << " at row " << r_lac << " was not booked." << endl;
    }
}

int main()
{
    createArray_lac();

    int choice_lac;
    do
    {
        cout << "\n--- Galaxy Multiplex Reservation System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_lac;

        switch (choice_lac)
        {
        case 1:
            DisplayAvailableSeats_lac();
            break;

        case 2:
        {
            int row_lac, seat_lac;
            cout << "Enter Row (1-8): ";
            cin >> row_lac;
            cout << "Enter Seat (1-8): ";
            cin >> seat_lac;
            if (row_lac >= 1 && row_lac <= 8 && seat_lac >= 1 && seat_lac <= 8)
                BookSeat_lac(row_lac, seat_lac);
            else
                cout << "Invalid row or seat number!\n";
            break;
        }

        case 3:
        {
            int row_lac, seat_lac;
            cout << "Enter Row (1-8): ";
            cin >> row_lac;
            cout << "Enter Seat (1-8): ";
            cin >> seat_lac;
            if (row_lac >= 1 && row_lac <= 8 && seat_lac >= 1 && seat_lac <= 8)
                CancelSeat_lac(row_lac, seat_lac);
            else
                cout << "Invalid row or seat number!\n";
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice_lac != 4);

    return 0;
}