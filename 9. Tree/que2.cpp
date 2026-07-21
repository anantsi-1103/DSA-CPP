#include <iostream>
#include <map>
#include <queue>
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

void top_view(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    //
    map<int, int> mp;

    // Stores the horizontal distances
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        Node *curr = q.front().first;

        int hd = q.front().second;
        q.pop();

        if (mp.find(hd) == mp.end())
        {
            mp[hd] = curr->data;
        }

        if (curr->left)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, hd + 1});
        }
    }
        cout<< "Top View : "<<endl;

        for(auto x : mp){
            cout<< x.second << endl;
        }
    
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    top_view(root);

    return 0;
}