#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {43, 56, 23, 65, 23, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<linearSearch(arr, 100, size)<<endl;
    return 0;
}