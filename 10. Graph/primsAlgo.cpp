#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void primMst(int V, vector<pair<int,int>> adj[]){
    vector<int> key (V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V , -1);
    
    // start from vertex 0
    key[0] = 0;
 
    // Run V-1 times // 0. 1 2 3 4
    for(int c = 0; c < V - 1; c++){
        // step 1 - find minimum key value
        int min = INT_MAX;
        int u = -1;

        for(int i = 0 ; i<V ; i++){
            if(!mst[i] && key[i] < min){
                min = key[i];
                u = i;
            }
        }
        // include in mst
        mst[u] = true;

        // update vertices / 0 -> 1 ,3 , 2 -> 
        for(auto it : adj[u]){
            int v = it.first; // 1
            int weight = it.second; // 2

            if(!mst[v] && weight < key[v]){
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // count - Edge and weight
    cout << "Edge \t Weight \n";
    int totalWeight = 0;

    for(int i = 1; i<V ; i++){
        cout<< parent[i] << " - " << i << "\t" << key[i] << endl;
        totalWeight += key[i];
    } 

    cout<< " \nTotal Weight = "<< totalWeight << endl;
}




int main()
{
    int V = 5;

    vector<pair<int,int>> adj[V];

    auto addEdge = [&](int u, int v, int wt)
    {
        // 0 - 1 
        // 1 - 0
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});// undirect
    };

    addEdge(0,1,2);
    addEdge(1,2,3);
    addEdge(0,3,6);
    addEdge(1,3,8);
    addEdge(1,4,5);
    addEdge(2,4,7);

    primMst(V, adj);

    return 0;
}