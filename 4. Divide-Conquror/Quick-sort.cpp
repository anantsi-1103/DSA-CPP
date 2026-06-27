#include <iostream>
using namespace std;

int parition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) //  3 -- 4
    { 
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = parition(arr, low, high); // pivot

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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
    quickSort(arr, 0, size - 1);
    cout << "After Sorted : ";
    printArray(arr, size);



    return 0;
}