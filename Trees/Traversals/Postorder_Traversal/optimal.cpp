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

void postorder(TreeNode* root, vector<int>& ans)
{
    if(root == NULL)
        return;

    postorder(root->left, ans);

    postorder(root->right, ans);

    ans.push_back(root->val);
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

    postorder(root, ans);

    cout << "Postorder Traversal : ";

    for(int x : ans)
        cout << x << " ";

    return 0;
}