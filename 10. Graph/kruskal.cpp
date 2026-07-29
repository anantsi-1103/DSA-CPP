#include <iostream>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    // Union by Rank
    bool Union(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        // already in a same set
        if (px == py)
        {
            return false;
        }

        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

struct Edge
{
    int u, v, wt;
};

bool cmp(Edge a, Edge b)
{
    return a.wt < b.wt;
}

int main()
{

    int V = 4;

    vector<Edge> edges = {
        {2, 3, 4},
        {0, 3, 5},
        {0, 2, 6},
        {0, 1, 10},
        {1, 3, 15},
    };

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int mst = 0;

    for (Edge e : edges)
    {
        if (dsu.Union(e.u, e.v))
        {
            cout << e.u << " - " << e.v << " : " << e.wt << endl;

            mst+= e.wt;
        }
    }

    cout<< "\n Total MST Cost : "<< mst << endl;
    return 0;
}