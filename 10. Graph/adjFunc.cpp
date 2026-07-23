#include <iostream>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected
}

int main()
{

    int V = 5;

    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 2);
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

    return 0;
}