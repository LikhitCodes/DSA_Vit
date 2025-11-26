#include <iostream>
#include <queue>
using namespace std;

void bfs_lac(int vertices_lac, int adjMatrix_lac[][10], int start_lac) {
    bool visited_lac[vertices_lac];
    for (int i_lac = 0; i_lac < vertices_lac; i_lac++)
        visited_lac[i_lac] = false;

    queue<int> q_lac;
    q_lac.push(start_lac);
    visited_lac[start_lac] = true;

    cout << "BFS Traversal: ";
    while (!q_lac.empty()) {
        int current_lac = q_lac.front();
        q_lac.pop();
        cout << current_lac << " ";
        for (int i_lac = 0; i_lac < vertices_lac; i_lac++) {
            if (adjMatrix_lac[current_lac][i_lac] && !visited_lac[i_lac]) {
                q_lac.push(i_lac);
                visited_lac[i_lac] = true;
            }
        }
    }
    cout << endl;
}

void dfs_lac(int vertices_lac, int adjMatrix_lac[][10], int start_lac) {
    bool visited_lac[vertices_lac];
    for (int i_lac = 0; i_lac < vertices_lac; i_lac++)
        visited_lac[i_lac] = false;

    int stack_lac[vertices_lac];
    int top_lac = -1;
    stack_lac[++top_lac] = start_lac;

    cout << "DFS Traversal: ";
    while (top_lac >= 0) {
        int current_lac = stack_lac[top_lac--];
        if (!visited_lac[current_lac]) {
            cout << current_lac << " ";
            visited_lac[current_lac] = true;
            for (int i_lac = vertices_lac - 1; i_lac >= 0; i_lac--) {
                if (adjMatrix_lac[current_lac][i_lac] && !visited_lac[i_lac]) {
                    stack_lac[++top_lac] = i_lac;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices_lac, choice_lac, start_lac;
    int adjMatrix_lac[10][10];

    cout << "Enter number of vertices: ";
    cin >> vertices_lac;

    cout << "Enter adjacency matrix:\n";
    for (int i_lac = 0; i_lac < vertices_lac; i_lac++) {
        for (int j_lac = 0; j_lac < vertices_lac; j_lac++) {
            cin >> adjMatrix_lac[i_lac][j_lac];
        }
    }

    while (true) {
        cout << "\n1. BFS Traversal\n2. DFS Traversal\n3. Exit\nEnter choice: ";
        cin >> choice_lac;

        if (choice_lac == 1) {
            cout << "Enter starting vertex (0-" << vertices_lac - 1 << "): ";
            cin >> start_lac;
            bfs_lac(vertices_lac, adjMatrix_lac, start_lac);
        }
        else if (choice_lac == 2) {
            cout << "Enter starting vertex (0-" << vertices_lac - 1 << "): ";
            cin >> start_lac;
            dfs_lac(vertices_lac, adjMatrix_lac, start_lac);
        }
        else if (choice_lac == 3) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
