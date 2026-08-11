#include <iostream>
using namespace std;

// Node of BST
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int val)
{
    // If tree is empty
    if(root == NULL)
    {
        return new Node(val);
    }

    // Go to left subtree
    if(val < root->data)
    {
        root->left = insert(root->left, val);
    }
    // Go to right subtree
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Inorder traversal (gives sorted order in BST)
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    // Insert elements
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}