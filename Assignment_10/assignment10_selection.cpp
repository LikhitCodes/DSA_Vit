#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int numEmployees_lac;
    cout << "Enter number of employees: ";
    cin >> numEmployees_lac;

    int *height_lac = new int[numEmployees_lac];
    int *weight_lac = new int[numEmployees_lac];
    float *average_lac = new float[numEmployees_lac];

    if (height_lac == NULL || weight_lac == NULL || average_lac == NULL){
        cout << "Memory not allocated";
        return -1;
    }

    cout << "Generated random height and weight:\n";
    for (int i_lac = 0; i_lac < numEmployees_lac; i_lac++) {
        height_lac[i_lac] = rand() % 61 + 140;
        weight_lac[i_lac] = rand() % 71 + 40;
        average_lac[i_lac] = (height_lac[i_lac] + weight_lac[i_lac]) / 2.0;
        cout << "Emp" << i_lac + 1 << ": " << height_lac[i_lac] << "cm, "
             << weight_lac[i_lac] << "kg -> Avg = " << average_lac[i_lac] << endl;
    }

    int passCount_lac = 1;
    cout << "\n--- Selection Sort Passes ---\n";
    for (int i_lac = 0; i_lac < numEmployees_lac - 1; i_lac++) {
        int minIndex_lac = i_lac;
        for (int j_lac = i_lac + 1; j_lac < numEmployees_lac; j_lac++) {
            if (average_lac[j_lac] < average_lac[minIndex_lac]) {
                minIndex_lac = j_lac;
            }
        }
        swap(average_lac[i_lac], average_lac[minIndex_lac]);

        cout << "Pass " << passCount_lac++ << ": ";
        for (int k_lac = 0; k_lac < numEmployees_lac; k_lac++) cout << average_lac[k_lac] << " ";
        cout << endl;
    }

    cout << "\nSorted averages:\n";
    for (int i_lac = 0; i_lac < numEmployees_lac; i_lac++) cout << average_lac[i_lac] << " ";

    cout << "\n\nTime Complexity: O(n^2)\n";

    delete[] height_lac;
    delete[] weight_lac;
    delete[] average_lac;

    return 0;
}