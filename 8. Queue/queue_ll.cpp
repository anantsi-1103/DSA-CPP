#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    void enqueue(int val)
    {
        Node *newNode = new Node(val);

        if (rear == NULL)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty \n";
            return;
        }

        Node *temp = front;

        cout << " deleted : " << temp->data << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    void display()
    {
        Node *temp = front;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void peek()
    {
        Node *temp = front;

        cout << "Top Most Element :  " << temp->data << endl;
    }
};

int main()
{

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();
    
    q.dequeue();

    q.display();

    q.peek();

    return 0;
}