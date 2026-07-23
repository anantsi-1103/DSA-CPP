#include <iostream>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";
        // n : 0 , 1
        // visit all neighbours
        for (int n : adj[node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

int main()
{

    int V = 5;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 4);

    // Print Adjancent List
    cout << "Adjacent List \n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        for (int n : adj[i])
        {
            cout << n << " ";
        }

        cout << endl;
    }

    vector<bool> visited(V, false);

    cout << "BFS Traversal : ";
    bfs(0, adj, visited);

    return 0;
}