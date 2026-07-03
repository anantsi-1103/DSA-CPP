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

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty \n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD) \n";
}

void insertAtStart(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL) // no list
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL) // no list
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail->next = head;
}

void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is Empty \n";
        return;
    }

    Node *temp = head;

    // only one element exist
    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    else
    {
        head = head->next;
        tail->next = head;
    }

    delete temp;
}

void deleteAtTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is Empty \n";
        return;
    }

    // only one element exist
    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next != tail)
    {
        temp = temp->next;
    }

    temp->next = head;

    delete tail;
    tail = temp;
}

// searching inat position delete by position
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtStart(head, tail, 30);
    insertAtStart(head, tail, 34);
    insertAtStart(head, tail, 65);
    insertAtStart(head, tail, 87);

    insertAtTail(head, tail, 99);
    insertAtTail(head, tail, 23);

    display(head);

    deleteAtTail(head, tail);

    display(head);

    return 0;
}