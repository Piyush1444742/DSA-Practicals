#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    string city[10];
    int a[10][10];
    int n;

public:
    void input();
    void display();
    void BFS();
    void DFS();
};

void Graph::input() {
    cout << "\nEnter no. of cities: ";
    cin >> n;
    cout << "\nEnter the names of cities:\n";
    for (int i = 0; i < n; i++)
        cin >> city[i];

    cout << "\nEnter the distances:\n";
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (i == j) {
                a[i][j] = 0;
                continue;
            }
            cout << "Distance between " << city[i] << " and " << city[j] << ": ";
            cin >> a[i][j];
            a[j][i] = a[i][j]; // symmetric matrix
        }
}

void Graph::display() {
    cout << "\nAdjacency Matrix:\n\t";
    for (int i = 0; i < n; i++)
        cout << city[i] << "\t";
    for (int i = 0; i < n; i++) {
        cout << "\n" << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
    }
    cout << endl;
}

void Graph::BFS() {
    cout << "\n\nBFS Traversal:\n";
    queue<int> q;
    int visit[10] = {0};
    string start;
    int index = -1;

    cout << "Enter starting city: ";
    cin >> start;

    for (int i = 0; i < n; i++) {
        if (start == city[i]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "City not found.\n";
        return;
    }

    q.push(index);
    visit[index] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << city[current] << " -> ";

        for (int i = 0; i < n; i++) {
            if (a[current][i] != 0 && visit[i] == 0) {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
    cout << "END\n";
}

void Graph::DFS() {
    cout << "\n\nDFS Traversal:\n";
    stack<int> s;
    int visit[10] = {0};
    string start;
    int index = -1;

    cout << "Enter starting city: ";
    cin >> start;

    for (int i = 0; i < n; i++) {
        if (start == city[i]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "City not found.\n";
        return;
    }

    s.push(index);
    visit[index] = 1;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << city[current] << " -> ";

        for (int i = n - 1; i >= 0; i--) {
            if (a[current][i] != 0 && visit[i] == 0) {
                s.push(i);
                visit[i] = 1;
            }
        }
    }
    cout << "END\n";
}

int main() {
    Graph g1;
    int choice;

    while (true) {
        cout << "\n\nGRAPH TRAVERSAL MENU";
        cout << "\n1. Input data";
        cout << "\n2. Display adjacency matrix";
        cout << "\n3. DFS Traversal";
        cout << "\n4. BFS Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: g1.input(); break;
            case 2: g1.display(); break;
            case 3: g1.DFS(); break;
            case 4: g1.BFS(); break;
            case 5: return 0;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    }
}
