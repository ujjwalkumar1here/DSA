#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
{
    vis[node] = 1;
    cout << node << " ";

    for(auto neighbour : adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour, adj, vis);
        }
    }
}

int main()
{
    int V = 5;

    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<int> vis(V, 0);

    cout << "DFS Traversal: ";

    dfs(0, adj, vis);

    return 0;
}