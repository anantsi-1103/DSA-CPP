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


    cout<<"Before Sorted : "<<endl;
    printArray(arr,size);
    
    BubbleSort(arr,size);
    
    cout<<"After Sorted : "<<endl;
    printArray(arr,size);


    return 0;
}