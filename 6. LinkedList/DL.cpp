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

// Display
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Count Nodes
int count(Node *head)
{
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// Insert at Head
void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
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

    Node *temp = head;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }

    delete temp;
}

// Delete Tail
void deleteTail(Node *&head, Node *&tail)
{
    if (tail == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = tail;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }

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
    int pos = 1;

    while (head != NULL)
    {
        if (head->data == key)
        {
            cout << key << " found at Position " << pos << endl;
            return;
        }

        head = head->next;
        pos++;
    }

    cout << key << " Not Found\n";
}

// Reverse Doubly Linked List
void reverse(Node *&head, Node *&tail)
{
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}

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

    cout << "\nReverse List:\n";
    reverse(head, tail);
    display(head);

    return 0;
}