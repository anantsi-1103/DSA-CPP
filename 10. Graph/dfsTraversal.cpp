#include <iostream>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int n : adj[node])
    {
        if (!visited[n])
        {
            dfs(n, adj, visited);
        }
    }
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

int main()
{

    int V = 5;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

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

    cout << "DFS Traversal : ";
    dfs(0, adj, visited);

    return 0;
}