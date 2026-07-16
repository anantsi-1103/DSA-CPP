#include <iostream>
#include <queue>
#include <algorithm>
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

//------------------ Preorder ------------------

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//------------------ Inorder ------------------

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//------------------ Postorder ------------------

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//------------------ Level Order ------------------

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
}

//------------------ Height ------------------

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

//------------------ Count Nodes ------------------

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

//------------------ Count Leaf Nodes ------------------

int leafNodes(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafNodes(root->left) + leafNodes(root->right);
}

//------------------ Search ------------------

bool search(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    return search(root->left, key) || search(root->right, key);
}

//------------------ Mirror Tree ------------------

void mirror(Node *root)
{
    if (root == NULL)
        return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

//=====================================================
// BST FUNCTIONS
//=====================================================

//------------------ BST Insert ------------------

Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

//------------------ BST Search ------------------

Node *searchBst(Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchBst(root->left, key);

    return searchBst(root->right, key);
}

//------------------ Minimum Node ------------------

Node *minValue(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

//------------------ Maximum Node ------------------

Node *maxValue(Node *root)
{
    while (root->right != NULL)
        root = root->right;

    return root;
}

//------------------ Delete Node ------------------

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // no child

        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // One CHild
        if (root->left == NULL)
        {
            Node *temp = root->right;

            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;

            delete root;
            return temp;
        }

        // two child
        Node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

//=====================================================
// MAIN
//=====================================================

int main()
{
    cout << "========== Binary Tree ==========\n\n";

    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Preorder : ";
    preOrder(root);

    cout << "\nInorder : ";
    inOrder(root);

    cout << "\nPostorder : ";
    postOrder(root);

    cout << "\nLevel Order : ";
    levelOrder(root);

    cout << "\nHeight : " << height(root);

    cout << "\nTotal Nodes : " << countNodes(root);

    cout << "\nLeaf Nodes : " << leafNodes(root);

    cout << "\nSearch 5 : ";
    if (search(root, 5))
        cout << "Found";
    else
        cout << "Not Found";

    mirror(root);

    cout << "\n\nAfter Mirror (Level Order) : ";
    levelOrder(root);

    //=====================================================
    // BST
    //=====================================================

    cout << "\n\n\n========== Binary Search Tree ==========\n\n";

    Node *bst = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : arr)
        bst = insert(bst, x);

    cout << "Inorder : ";
    inOrder(bst);

    cout << "\nPreorder : ";
    preOrder(bst);

    cout << "\nPostorder : ";
    postOrder(bst);

    cout << "\nLevel Order : ";
    levelOrder(bst);

    cout << "\nHeight : " << height(bst);

    cout << "\nTotal Nodes : " << countNodes(bst);

    cout << "\nMinimum : " << minValue(bst)->data;

    cout << "\nMaximum : " << maxValue(bst)->data;

    cout << "\nSearch 60 : ";

    if (searchBst(bst, 60))
        cout << "Found";
    else
        cout << "Not Found";


    bst = deleteNode(bst, 20);

    cout<< "\n\nAfter Deleting 20: \n";
    inOrder(bst);

    cout << endl;

    return 0;
}