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

    // Insert at Front
    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "Deque Overflow\n";
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

        arr[front] = value;
    }

    // Insert at Rear
    void insertRear(int value)
    {
        if (isFull())
        {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
    }

    // Delete Front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted : " << arr[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete Rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow\n";
            return;
        }

        cout << "Deleted : " << arr[rear] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    void getFront()
    {
        if (isEmpty())
        {
            cout << "Deque Empty\n";
            return;
        }

        cout << "Front = " << arr[front] << endl;
    }

    void getRear()
    {
        if (isEmpty())
        {
            cout << "Deque Empty\n";
            return;
        }

        cout << "Rear = " << arr[rear] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque Empty\n";
            return;
        }

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main()
{
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);

    dq.display();

    dq.insertFront(5);
    dq.display();

    dq.insertRear(40);
    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    dq.getFront();
    dq.getRear();

    return 0;
}