#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow \n";
            return;
        }

        arr[++top] = x;
        // arr[0]
        cout << x << ": inserted  \n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow \n";
            return;
        }

        cout << arr[top] << " \n Deleted \n";
        top--;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty \n";
            return;
        }

        cout << "Top Element : " << arr[top] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack :- \n";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void size()
    {
        cout << "Size : " << top + 1 << endl;
    }
};

int main()
{

    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();
    s.display();

    return 0;
}