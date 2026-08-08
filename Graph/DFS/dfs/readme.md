# DFS Traversal of Graph

## Approach : Depth First Search (DFS)

### Idea

DFS (Depth First Search) explores a graph by going **as deep as possible** before backtracking.

We use:

* **Adjacency List** → stores neighbours of every node
* **Visited Array** → prevents visiting the same node again
* **Recursion** → automatically handles backtracking

---

## DFS Function

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
{
    vis[node] = 1;

    for(auto neighbour : adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour, adj, vis);
        }
    }
}
```

---

## Example Graph

```text
        0
      /   \
     1     2
    / \
   3   4
```

Adjacency List

```text
0 → 1 2
1 → 0 3 4
2 → 0
3 → 1
4 → 1
```

---

## DFS Traversal

Starting from node `0`

```text
0 → 1 → 3 → 4 → 2
```

Output

```text
0 1 3 4 2
```

---

## Dry Run

Initially

```text
Visited = [0,0,0,0,0]
```

Visit `0`

```text
Visited = [1,0,0,0,0]
```

Visit `1`

```text
Visited = [1,1,0,0,0]
```

Visit `3`

```text
Visited = [1,1,0,1,0]
```

Backtrack to `1`

Visit `4`

```text
Visited = [1,1,0,1,1]
```

Backtrack to `0`

Visit `2`

```text
Visited = [1,1,1,1,1]
```

All nodes are visited.

---

## Time Complexity

```text
O(V + E)
```

Where:

* `V` = Number of Vertices
* `E` = Number of Edges

Reason:

* Every vertex is visited once.
* Every edge is explored once.

---

## Space Complexity

```text
O(V)
```

Reason:

* Visited array
* Recursive call stack

---

## Important Points

✅ Mark the node as visited before recursion.

✅ Use recursion to explore neighbours deeply.

✅ DFS follows **Depth → Backtrack → Next Path**.

✅ Same template is used in many graph problems.

---

## Core Template

```cpp
vis[node] = 1;

for(auto neighbour : adj[node])
{
    if(!vis[neighbour])
    {
        dfs(neighbour, adj, vis);
    }
}
```

---

## Used In

* DFS Traversal
* Number of Islands
* Flood Fill
* Number of Provinces
* Connected Components
* Cycle Detection
* Topological Sort
* Course Schedule

---

## Pattern

```text
Graph Traversal
      ↓
Visited Array
      ↓
Recursion
      ↓
Depth First Search
```
