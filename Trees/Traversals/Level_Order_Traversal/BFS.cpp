#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        vector<int> level;

        for(int i = 0; i < size; i++)
        {
            TreeNode* temp = q.front();
            q.pop();

            level.push_back(temp->val);

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }

        ans.push_back(level);
    }

    return ans;
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

    vector<vector<int>> ans = levelOrder(root);

    cout << "Level Order Traversal:\n";

    for(auto level : ans)
    {
        for(int x : level)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}