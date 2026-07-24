#include <iostream>
#include <set>
#include <vector>

using namespace std;

void dijkstra(int V, vector<pair<int, int>> adj[], int src)
{
    vector<int> dist(V, INT_MAX);
    // {distance : node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    // Source Distance = 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        // 0,0 , {8,2}
        int dis= pq.top().first;
        int node = pq.top().second;

        pq.pop();

        // visit all neighbours
        // {5,1} 
        // 0,5 2,9 3,2
        // 0,8
        for(auto it : adj[node]){
            int adjNode = it.first;
            int weight = it.second;

            if(dis + weight < dist[adjNode]){
                dist[adjNode] = dis + weight;
                // dist[1] = 5
                // 5,1
                // dist[2] = 8
                // dist[3] = 7
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout<< "Shortest Distance From Source " << src << endl;

    for(int i = 0; i<V ; i++){
        cout<< i << " -> " << dist[i] << endl;
    }
}

int main()
{

    int V = 4;

    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});

    adj[0].push_back({2, 8});
    adj[2].push_back({0, 8});

    adj[1].push_back({2, 9});
    adj[2].push_back({1, 9});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[2].push_back({3, 6});
    adj[3].push_back({2, 6});

    dijkstra(V, adj, 0);

    return 0;
}