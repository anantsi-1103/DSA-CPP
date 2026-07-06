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
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second = reverse(slow->next);

    Node *first = head;

    while (second)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }

    return true;
}
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

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    // Node *head = NULL;

    // insertAtHead(head, 10);
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    // insertAtHead(head, 50);
    // insertAtHead(head, 10);

    // print(head);

    // cout << isPalindrome(head);
    // return 0;

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create Cycle
    // head->next->next->next->next->next = head->next->next;

    if (detectCycle(head))
    {
        cout << "Cycle Detected: \n";
    }
    else
    {
        cout << "Cycle Not Detected \n";
    }

    // print(head);
}