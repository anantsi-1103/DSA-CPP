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

    void printParent()
    {
        cout << "Parent : ";
        for (int x : parent)
        {
            cout << x << " ";
        }
        cout << " ";
    }

    void printRank()
    {
        cout << "Rank : ";
        for (int x : rank)
        {
            cout << x << " ";
        }
        cout << " ";
    }
};
int main()
{

    DSU dsu(6);

    dsu.printParent();
    dsu.printRank();

    cout << "\n Union (0,2) \n";
    dsu.Union(0, 2);
    dsu.printParent();
    dsu.printRank();

    cout << "\n Find  (2) : " << dsu.find(2) << endl;

    cout << "\n Union (1,3) \n";
    dsu.Union(1, 3);
    dsu.printParent();
    dsu.printRank();
    
    cout << "\n Union (2,5) \n";
    dsu.Union(2, 5);
    dsu.printParent();
    dsu.printRank();
    
    cout << "\n Union (0,3) \n";
    dsu.Union(0, 3);
    dsu.printParent();
    dsu.printRank();

    
    cout << "\n Union (0,4) \n";
    dsu.Union(0, 4);
    dsu.printParent();
    dsu.printRank();



    return 0;
}