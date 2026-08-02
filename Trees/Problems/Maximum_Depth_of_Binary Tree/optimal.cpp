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

int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    /*
            3
          /   \
         9     20
              /  \
             15   7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Depth : " << maxDepth(root);

    return 0;
}