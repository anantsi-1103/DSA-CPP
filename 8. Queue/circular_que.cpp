#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow \n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else
            // find the position
            rear = (rear + 1) % size;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow \n";
            return;
        }

        cout << "Deleted : " << arr[front] << endl;

        if (front > rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void getFront()
    {
        if (front == -1)
        {
            cout << " Queue Empty or Front is Out of Queue \n";
        }
        else
        {
            cout << "Front : " << arr[front] << endl;
        }
    }

    void getRear()
    {
        if (rear == -1)
        {
            cout << " Queue Empty or rear is Out of Queue \n";
        }
        else
        {
            cout << "Rear : " << arr[rear] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                cout << "rear\n";
                break;
            }
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    q.getFront();
    q.getRear();

    return 0;
}