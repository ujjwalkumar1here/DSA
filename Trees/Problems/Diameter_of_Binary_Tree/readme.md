# Diameter of Binary Tree (LeetCode 543)

## Idea

For every node,

- Find left subtree height.
- Find right subtree height.
- Update diameter.
- Return current node height.

---

## Formula

Update Diameter

```cpp
diameter = max(diameter, leftHeight + rightHeight);
```

Return Height

```cpp
return 1 + max(leftHeight, rightHeight);
```

---

## Dry Run

Tree

        1
       / \
      2   3
     / \
    4   5

Node 4

Height = 1

Diameter = 0

↓

Node 5

Height = 1

Diameter = 0

↓

Node 2

Left Height = 1

Right Height = 1

Diameter = 2

Height = 2

↓

Node 3

Height = 1

↓

Node 1

Left Height = 2

Right Height = 1

Diameter = 3

Height = 3

Answer = 3

---

## Time Complexity

O(n)

---

## Space Complexity

O(h)

h = Height of Tree

---

## Important Points

✅ Helper function returns **Height**.

✅ Diameter is updated using

```cpp
leftHeight + rightHeight
```

✅ Final answer is stored in the global variable `diameter`.

---

## Pattern

DFS + Height Calculation