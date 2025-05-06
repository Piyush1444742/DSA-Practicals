#include <iostream>
using namespace std;

class Office {
    int n;
    int a[10][10];
    string office[10];

public:
    void input();
    void display();
    void Prims();
};

void Office::input() {
    cout << "\nEnter number of offices: ";
    cin >> n;

    cout << "Enter the names of the offices:\n";
    for (int i = 0; i < n; i++)
        cin >> office[i];

    cout << "\nEnter the cost to connect the offices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                a[i][j] = 0;
            } else {
                cout << "Cost to connect " << office[i] << " and " << office[j] << ": ";
                cin >> a[i][j];
                a[j][i] = a[i][j];
            }
        }
    }
}

void Office::display() {
    cout << "\nCost Adjacency Matrix:\n\t";
    for (int i = 0; i < n; i++)
        cout << office[i] << "\t";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << office[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
}

void Office::Prims() {
    int visit[10] = {0};  // Fixed-size array for safety
    int cost = 0;
    int edges = 0;

    visit[0] = 1;
    cout << "\nEdges in the Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = 9999;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++) {
            if (visit[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visit[j] && a[i][j] && a[i][j] < min) {
                        min = a[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            cout << office[x] << " -> " << office[y] << " = " << a[x][y] << "\n";
            visit[y] = 1;
            cost += a[x][y];
            edges++;
        } else {
            cout << "Graph is not connected.\n";
            return;
        }
    }

    cout << "\nTotal Minimum Cost: " << cost << "\n";
}

int main() {
    Office o1;
    int choice;

    while (true) {
        cout << "\n\n==== MINIMUM SPANNING TREE MENU ====";
        cout << "\n1. Input data";
        cout << "\n2. Display matrix";
        cout << "\n3. Calculate minimum cost (Prim's)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: o1.input(); break;
            case 2: o1.display(); break;
            case 3: o1.Prims(); break;
            case 4: return 0;
            default: cout << "\nInvalid choice. Try again!\n";
        }
    }

    return 0;
}
