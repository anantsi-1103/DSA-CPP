#include <iostream>
using namespace std;

class Deque
{
    int *arr;
    int front, rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (front == (rear + 1) % size);
    }

    // insert at front
    void insertAtFront(int val)
    {
        if (isFull())
        {
            cout << "Dequeu is Full \n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = val;
    }

    // insert at rear ->
    void insertAtRear(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow \n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }

        else if (rear == size - 1)
            // find the position
            rear = 0;
        else
        {
            rear++;
        }

        arr[rear] = val;
    }

    // delete front
    // delete rear
    // display
};

int main()
{

    return 0;
}