#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printKLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }

    printKLevel(root->left, k - 1);
    printKLevel(root->right, k - 1);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    int k = 3;

    printKLevel(root, k);
    return 0;
}