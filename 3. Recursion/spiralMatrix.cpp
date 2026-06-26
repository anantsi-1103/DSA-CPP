#include <iostream>
using namespace std;

void printSpiral(int arr[4][4], int rows, int cols)
{
    int sr = 0;
    int sc = 0;
    int er = rows - 1;
    int ec = cols - 1;

    while (sr <= er && sc <= ec)
    {
        // Top
        for (int j = sc; j <= ec; j++)
        {
            cout << arr[sr][j] << " ";
        }
        sr++;

        // Right
        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][ec] << " ";
        }
        ec--;

        // bottom
        if (sr <= er)
        {
            for (int j = ec; j >= sc; j--)
            {
                cout << arr[er][j] << " ";
            }
            er--;
        }

        // left
        if (sc <= ec)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << arr[i][sc] << " ";
            }
            sc++;
        }
    }
}

int main()
{
    int arr[4][4] =
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}};

    printSpiral(arr, 4, 4);

    return 0;
}
