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

    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

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
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
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
            return true;
    }

    return false;
}

void removeCycle(Node *head)
{

    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // find the start of cycle
    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // find the last node
    while (fast->next != slow)
    {
        fast = fast->next;
    }

    // remove
    fast->next = NULL;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create Cycle
    head->next->next->next->next->next = head->next->next;

    if (detectCycle(head))
    {
        cout << " Cycle Detected : \n";
    }
    else
    {
        cout << " Cycle Not Detected: \n";
    }

    // removeCycle(head);

    if (detectCycle(head))
    {
        cout << " Cycle Detected : \n";
    }
    else
    {
        cout << " Cycle Not Detected: \n";
    }

    return 0;
}