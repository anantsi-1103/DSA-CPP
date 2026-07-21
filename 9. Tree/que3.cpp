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

int transform(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = transform(root->left);
    int rightSum = transform(root->right);
    int oldValue = root->data;

    root->data = leftSum + rightSum;

    return oldValue + root->data;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);

    cout << root->data << " ";

    inOrder(root->right);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(7);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    inOrder(root);
    cout<<endl;
    transform(root);
    cout<<endl;
    inOrder(root);

    return 0;
}