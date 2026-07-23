#include <iostream>
using namespace std;

int main()
{
    int V = 5;

    int adj[5][5] = {0};

    // adding

    adj[0][1] = adj[1][0] = 1;
    adj[0][4] = adj[4][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[3][2] = adj[2][3] = 1;
    adj[3][4] = adj[4][3] = 1;

    cout << "Adjaency Matrix \n\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}