# Maximum Depth of Binary Tree (LC 104)

## Idea

Find the height of the left subtree.

Find the height of the right subtree.

Return

```cpp
1 + max(leftHeight, rightHeight)
```

---

## Base Case

```cpp
if(root == NULL)
    return 0;
```

---

## Formula

```cpp
return 1 + max(leftHeight, rightHeight);
```

---

## Time Complexity

O(n)

---

## Space Complexity

O(h)

h = Height of the tree

---

## Pattern

DFS + Recursion

---

## Important Points

- Height of an empty tree = 0.
- Height of a leaf node = 1.
- Compute left and right heights recursively.
- Add 1 for the current node.