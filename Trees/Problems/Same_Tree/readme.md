# Same Tree (LeetCode 100)

## Idea

Compare both trees node by node.

Trees are same if

- Both nodes are NULL.
- Values are equal.
- Left subtrees are same.
- Right subtrees are same.

---

## Base Cases

```cpp
if(p == NULL && q == NULL)
    return true;

if(p == NULL || q == NULL)
    return false;
```

---

## Recursive Formula

```cpp
return isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right);
```

---

## Dry Run

Tree 1          Tree 2

    1               1
   / \             / \
  2   3           2   3

Compare

1 == 1 ✔

↓

2 == 2 ✔

↓

3 == 3 ✔

Answer = true

---

## Time Complexity

O(n)

---

## Space Complexity

O(h)

h = Height of Tree

---

## Important Points

✅ Both NULL → Same Tree

✅ One NULL → Not Same Tree

✅ Compare values before recursive calls.

✅ Compare Left and Right recursively.

---

## Pattern

DFS + Recursion + Compare Two Trees