#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = top;
        top = newNode;

        cout << val << "Inserted \n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! \n";
            return;
        }

        Node *temp = top;
        cout << top->data << "Deleted \n";
        top = top->next;

        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! \n";
            return;
        }

        cout << "Top : " << top->data << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! \n";
            return;
        }

        Node *temp = top;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void size()
    {
        Node *temp = top;

        int count = 0;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        cout << "Size of Stack is " << count << endl;
    }
};

int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();
    s.display();

    return 0;
}