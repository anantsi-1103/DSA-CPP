#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6, 8, 0, 1, 3};
    int ans[] = {};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
            else
            {
                ans[i] = -1;
                ans[n-1] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}