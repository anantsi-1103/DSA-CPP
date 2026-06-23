#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int size)
{
    int si = 0;
    int ei = size - 1;

    while (si <= ei)
    {
        int mid = (si + ei) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 14, 16, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << BinarySearch(arr, 16, size) << endl;
    return 0;
}