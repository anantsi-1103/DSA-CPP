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

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val); // insert new node

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val); // insert new node

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteHead(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    head = head->next;

    delete temp;
}

void deleteTail(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;
}

bool search(Node *&head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }

        head = head->next;
    }
    return false;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// delete by count ->

int main()
{

    Node *head = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 33);
    insertAtHead(head, 54);
    print(head);

    insertAtTail(head, 35);

    print(head);

    deleteTail(head);

    print(head);

    cout << search(head, 200) << endl;


    return 0;
}