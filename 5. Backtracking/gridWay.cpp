#include <iostream>
using namespace std;

int gridWay(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    if (i >= n || j >= m)
    {
        return 0;
    }

    int right = gridWay(i, j + 1, n, m);
    int down = gridWay(i + 1, j, n, m);

    return right + down;
}

int main()
{
    cout << gridWay(0, 0, 3, 3) << endl;

    return 0;
}