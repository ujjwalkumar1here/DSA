#include <iostream>

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

bool isSameTree(TreeNode* p, TreeNode* q)
{
    // Both nodes are NULL
    if(p == NULL && q == NULL)
        return true;

    // One node is NULL
    if(p == NULL || q == NULL)
        return false;

    // Values are different
    if(p->val != q->val)
        return false;

    // Compare left and right subtrees
    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main()
{
    /*
            Tree 1              Tree 2

               1                   1
             /   \               /   \
            2     3             2     3
    */

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    if(isSameTree(root1, root2))
        cout << "Same Tree";
    else
        cout << "Not Same Tree";

    return 0;
}