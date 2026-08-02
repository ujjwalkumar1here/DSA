#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int diameter = 0;

// Returns height of the tree
int height(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Update diameter
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root)
{
    diameter = 0;

    height(root);

    return diameter;
}

int main()
{
    /*
              1
             / \
            2   3
           / \
          4   5

    Diameter = 3
    Path = 4 -> 2 -> 1 -> 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of Binary Tree : "
         << diameterOfBinaryTree(root);

    return 0;
}