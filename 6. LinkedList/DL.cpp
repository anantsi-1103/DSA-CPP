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
        this->data = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " <->  ";
        head = head->next;
    }
}

void insertAtStart(Node *head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
    }

    if (head != NULL) // exisiting to new one
    {
        head->prev = newNode;
    }

    // newone to existing
    newNode->next = head;
    head = newNode;
}

// insert at end 
// insert at position
// delete front
// delete end
// delete at position
// reverse
//


int main()
{

    return 0;
}