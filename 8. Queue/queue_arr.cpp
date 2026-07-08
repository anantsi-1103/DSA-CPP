#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, size;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow \n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        arr[++rear] = val;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow \n";
            return;
        }

        cout << "Deleted : " << arr[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
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
        if (front == -1)
        {
            cout << " Queue Empty or Front is Out of Queue \n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " - ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);

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