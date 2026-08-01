#include <iostream>
#include <vector>

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

void preorder(TreeNode* root, vector<int>& ans)
{
    // Base Case
    if(root == NULL)
        return;

    // Visit Root
    ans.push_back(root->val);

    // Traverse Left Subtree
    preorder(root->left, ans);

    // Traverse Right Subtree
    preorder(root->right, ans);
}

int main()
{
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans;

    preorder(root, ans);

    cout << "Preorder Traversal : ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}