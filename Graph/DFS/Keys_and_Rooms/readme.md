# Keys and Rooms (LeetCode 841)

## Approach : Depth First Search (DFS)

### Idea

Initially, only **Room 0** is unlocked.

Each room may contain keys to other rooms.

Treat each room as a graph node.

A key from one room to another is an edge.

Start DFS from Room 0 and visit every reachable room.

If every room is visited, return `true`; otherwise return `false`.

---

## Graph Representation

Example

```text
rooms = [[1],[2],[3],[]]
```

Graph

```text
0 → 1 → 2 → 3
```

Starting from Room 0, DFS visits every room.

Answer

```text
true
```

---

## Algorithm

1. Create a visited array.

2. Start DFS from Room 0.

3. Mark the current room as visited.

4. For every key in the room:
   - If the room has not been visited,
   - Visit it recursively.

5. After DFS finishes, check if every room has been visited.

---

## DFS Function

```cpp
void dfs(int room)
{
    vis[room] = 1;

    for(auto key : rooms[room])
    {
        if(!vis[key])
        {
            dfs(key);
        }
    }
}
```

---

## Dry Run

Input

```text
rooms =

[
 [1],
 [2],
 [3],
 []
]
```

Initially

```text
Visited

0 0 0 0
```

Visit Room

```text
0
```

Visited

```text
1 0 0 0
```

Key found

```text
1
```

↓

Visit Room

```text
1
```

Visited

```text
1 1 0 0
```

Key

```text
2
```

↓

Visit Room

```text
2
```

Visited

```text
1 1 1 0
```

Key

```text
3
```

↓

Visit Room

```text
3
```

Visited

```text
1 1 1 1
```

All rooms visited.

Answer

```text
true
```

---

## Time Complexity

O(V + E)

Where

- V = Number of Rooms
- E = Total Number of Keys

---

## Space Complexity

O(V)

Reason:

- Visited array
- Recursive stack

---

## Important Points

✅ Treat every room as a graph node.

✅ Keys represent edges.

✅ DFS starts from Room 0.

✅ Visit every reachable room.

✅ Finally check if every room was visited.

---

## Pattern

Graph Traversal

Depth First Search

Connected Graph