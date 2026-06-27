#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1; // 4
    int n2 = high - mid;    // 3

    int left[n1], right[n2];

    // left[4] , right[3]

    // arr se value nikal ke left arr ke andr store krdiya
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    // remaining element 
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);      // left
        mergeSort(arr, mid + 1, high); // right

        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorted : ";
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);
    cout << "After Sorted : ";
    printArray(arr, size);

    return 0;
}


// Best -> O(n log n)