#include <iostream>
#include <list>
using namespace std;

bool search(list<int> table[], int key)
{
    int index = key % 5;

    for (int x : table[index])
    {
        if (x == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    const int SIZE = 5;

    list<int> hashTable[SIZE];

    int arr[] = {10, 20, 30, 15, 26, 38};

    for (int x : arr)
    {
        int index = x % SIZE;
        hashTable[index].push_back(x);
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " -> ";

        for (int x : hashTable[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }


    cout<< search(hashTable, 25) << endl;

    // STL -> unorderd Map , unordered Set -> Hash Tables

    return 0;
}