#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// count nodes
int count(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int c = 1;
    Node *temp = head;

    while (temp->next != head)
    {
        c++;
        temp = temp->next;
    }

    return c;
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD) \n";
}

// insert at head
void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    newNode->next = head;
    newNode->prev = tail;

    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
}

void deleteAtHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is Empty \n";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = head;

    head = head->next;
    head->prev = tail;
    tail->next = head;

    delete temp;
}

void deleteAtEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is Empty \n";
        return;
    }

    if (head == tail)
    {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = tail;

    tail = tail->prev;
    tail->next = head;
    head->prev = tail;

    delete temp;
}

void search(Node *head, int key)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;
    int pos = 1;

    do
    {
        if (temp->data == key)
        {
            cout << key << "Found at Position  : " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    } while (temp != head);

    cout << key << "Not found!!! ";
}

void reverse(Node *&head, Node *&tail)
{
    if (head == NULL || head == tail)
    {
        return;
    }

    Node *curr = head;

    do
    {

        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    } while (curr != head);

    Node *temp = head;
    head = tail;
    tail = temp;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);

    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);

    display(head);

    reverse(head, tail);

    display(head);

    return 0;
}