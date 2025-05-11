/*
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (u v):
0 1
0 2
1 3
1 4
2 4
3 4
Enter the starting vertex for traversal: 0


BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2
DFS Iterative Traversal: 0 2 4 1 3

*/





#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void DFSIterative(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Iterative Traversal: ";
        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
            }

            for (auto it = adjList[current].rbegin(); it != adjList[current].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges, u, v, start;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Perform BFS\n";
        cout << "2. Perform DFS (Recursive)\n";
        cout << "3. Perform DFS (Iterative)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting vertex for BFS: ";
                cin >> start;
                g.BFS(start);
                break;
            case 2:
                cout << "Enter the starting vertex for DFS (Recursive): ";
                cin >> start;
                g.DFS(start);
                break;
            case 3:
                cout << "Enter the starting vertex for DFS (Iterative): ";
                cin >> start;
                g.DFSIterative(start);
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}