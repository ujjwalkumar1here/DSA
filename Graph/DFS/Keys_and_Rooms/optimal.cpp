#include <iostream>
#include <vector>

using namespace std;

void dfs(int room, vector<vector<int>>& rooms, vector<int>& vis)
{
    vis[room] = 1;

    for(auto key : rooms[room])
    {
        if(!vis[key])
        {
            dfs(key, rooms, vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    int n = rooms.size();

    vector<int> vis(n, 0);

    dfs(0, rooms, vis);

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> rooms = {
        {1},
        {2},
        {3},
        {}
    };

    if(canVisitAllRooms(rooms))
        cout << "True";
    else
        cout << "False";

    return 0;
}