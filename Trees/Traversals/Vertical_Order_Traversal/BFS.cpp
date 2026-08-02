#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

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

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    // Column -> Row -> Sorted Values
    map<int, map<int, multiset<int>>> nodes;

    // Node , {Column , Row}
    queue<pair<TreeNode*, pair<int,int>>> q;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        auto current = q.front();
        q.pop();

        TreeNode* node = current.first;
        int col = current.second.first;
        int row = current.second.second;

        nodes[col][row].insert(node->val);

        if(node->left)
            q.push({node->left,{col-1,row+1}});

        if(node->right)
            q.push({node->right,{col+1,row+1}});
    }

    for(auto column : nodes)
    {
        vector<int> temp;

        for(auto row : column.second)
        {
            for(int value : row.second)
            {
                temp.push_back(value);
            }
        }

        ans.push_back(temp);
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
              15    7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);

    cout << "Vertical Traversal:\n";

    for(auto column : ans)
    {
        for(int value : column)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}