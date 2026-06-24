#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int max = i;

        for (int j = i + 1; j < size; j++)
        {
            // to find the smallest index
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }

        // int temp = arr[i];
        // arr[i] = arr[max];
        // arr[max] = temp;

        swap(arr[i], arr[max]);
    }
}

void insertionSort(int arr[], int size){
    for(int i = 1; i<size ; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] < key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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
    int arr[] = {5, 4, 3, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorted : " << endl;
    printArray(arr, size);

    // BubbleSort(arr, size);
    // selectionSort(arr, size);
    insertionSort(arr,size);

    cout << "After Sorted : " << endl;
    printArray(arr, size);

    return 0;
}