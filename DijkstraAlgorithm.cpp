#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {

        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {

                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if (record != st.end())
                {
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;

                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main()
{
    int vertices, edges;
    vector<vector<int>> edgesList;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    edgesList.resize(edges, vector<int>(3));
    cout << "Enter the edges (u v w):" << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> edgesList[i][0] >> edgesList[i][1] >> edgesList[i][2];
    }

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Find shortest path using Dijkstra's algorithm\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int source;
            cout << "Enter the source vertex: ";
            cin >> source;

            vector<int> shortestDistances = dijkstra(edgesList, vertices, edges, source);

            cout << "Shortest distances from source " << source << ":\n";
            for (int i = 0; i < vertices; i++)
            {
                cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
            }
            break;
        }
        case 2:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

/*

Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (u v w):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1

Menu:
1. Find shortest path using Dijkstra's algorithm
2. Exit
Enter your choice: 1
Enter the source vertex: 0

--------------------------------------------------------------------------------------------------------------

Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (u v w):
0 1 1
0 2 4
1 2 2
1 3 6
2 3 3

Menu:
1. Find shortest path using Dijkstra's algorithm
2. Exit
Enter your choice: 1
Enter the source vertex: 1


Summary:
- Time Complexity: O((V + E) * log V)
- Space Complexity:O(V + E)

*/