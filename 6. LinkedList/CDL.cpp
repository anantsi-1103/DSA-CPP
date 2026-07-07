#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Count Nodes
int count(Node *head)
{
    if (head == NULL)
        return 0;

    int cnt = 1;
    Node *temp = head;

    while (temp->next != head)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// Display
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

// Insert at Head
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

// Insert at Tail
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

// Insert at Position
void insertAtPosition(Node *&head, Node *&tail, int pos, int val)
{
    int n = count(head);

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }

    if (pos == n + 1)
    {
        insertAtTail(head, tail, val);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    Node *newNode = new Node(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete Head
void deleteHead(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
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

// Delete Tail
void deleteTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
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

// Delete at Position
void deleteAtPosition(Node *&head, Node *&tail, int pos)
{
    int n = count(head);

    if (pos < 1 || pos > n)
    {
        cout << "Invalid Position\n";
        return;
    }

    if (pos == 1)
    {
        deleteHead(head, tail);
        return;
    }

    if (pos == n)
    {
        deleteTail(head, tail);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

// Search
void search(Node *head, int key)
{
    if (head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head;
    int pos = 1;

    do
    {
        if (temp->data == key)
        {
            cout << key << " Found at Position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;

    } while (temp != head);

    cout << key << " Not Found\n";
}

// Reverse Circular Doubly Linked List
void reverse(Node *&head, Node *&tail)
{
    if (head == NULL || head == tail)
        return;

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

// Main
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    cout << "Original List:\n";
    display(head);

    insertAtPosition(head, tail, 3, 25);
    cout << "\nAfter Insert at Position 3:\n";
    display(head);

    deleteHead(head, tail);
    cout << "\nAfter Delete Head:\n";
    display(head);

    deleteTail(head, tail);
    cout << "\nAfter Delete Tail:\n";
    display(head);

    deleteAtPosition(head, tail, 2);
    cout << "\nAfter Delete Position 2:\n";
    display(head);

    cout << "\nSearching 40:\n";
    search(head, 40);

    cout << "\nAfter Reverse:\n";
    reverse(head, tail);
    display(head);

    return 0;
}